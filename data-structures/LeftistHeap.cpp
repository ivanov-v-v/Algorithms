struct LeftistNode {
    int key;
    unsigned rank;
    LeftistNode *tl, *tr, *pr;
    LeftistNode(int K): key(K), rank(1) {
        tl = tr = pr = nullptr;
    }
};

typedef LeftistNode* pnode;
unsigned getRank(pnode T) {
    return T ? T->rank : 0;
}
void update(pnode T) {
    if (!T) return;
    T->rank = min(getRank(T->tl), getRank(T->tr)) + 1;
}

pnode merge(pnode& L, pnode& R) {
    if (!L || !R) {
        return L ? L : R;
    }
    if (L->key > R->key) {
        swap(L, R);
    }
    L->tr = merge(L->tr, R);
    if (getRank(L) < getRank(R)) {
        swap(L, R);
    }
    R->pr = L, L->pr = nullptr;
    update(L);
    return L;
}

void insert(pnode& root, const int& key) {
    pnode T0 = new LeftistNode(key);
    root = merge(root, T0);
//    cout << root->key << endl;
}
int getMin(pnode root) {
    if (!getRank(root)) {
        throw logic_error("Empty heap");
    }
    return root->key;
}
int extractMin(pnode& root) {
    if (!getRank(root)) {
        throw logic_error("Empty heap");
    }
    int result = root->key;
    root = merge(root->tl, root->tr);
    return result;
}
void deleteNode(pnode node) {
    pnode backLink = node->pr;
    node = merge(node->tl, node->tr);
    node->pr = backLink;
    while (node->pr) {
        node->pr->rank = min(getRank(node->pr->tl), getRank(node->pr->tr)) + 1;
        node = node->pr;
    }
}
