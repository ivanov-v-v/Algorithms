struct Node {
    int key, priority;
    Node *tl, *tr, *tp;
    Node(){
        key = 0;
        priority = rand();
        tl = tr = tp = nullptr;
    }
};
typedef Node* pnode;

pnode Merge(pnode& L, pnode& R) { // all keys in R are not less then all keys in L
    if (!L || !R) {
        return L ? L : R;
    }
    if (L->priority < R->priority) {
        L->tp = R, R->tp = nullptr;
        R->tl = Merge(L, R->tl);
        return R;
    } else {
        L->tp = nullptr, R->tp = L;
        L->tr = Merge(L->tr, R);
        return L;
    }
}
void Split(pnode root, int key, pnode& L, pnode& R) {
    if (!root) {
        L = R = nullptr;
        return;
    }
    if (key <= root->key) {
        Split(root->tl, key, L, root->tl);
        R = root;
    } else {
        Split(root->tr, key, root->tr, R);
        L = root;
    }
}
void Traverse(pnode root) {
    if (!root) {
        return;
    }
    Traverse(root->tl);
    cout << root->key << " ";
    Traverse(root->tr);
}
void Build(pnode& root, int* a, int n) { // it's assumed, that elements of a come in ascending order
    pnode largestNode = nullptr;
    for (int i = 0; i < n; ++i) {
        pnode T = new Node();
        T->key = a[i];
        if (!largestNode) {
            root = largestNode = T;
        } else if (T->priority <= largestNode->priority) {
            largestNode->tr = T;
            T->tp = largestNode;
            largestNode = T;
        } else {
            pnode curr = largestNode;
            while (curr && curr->priority < T->priority) {
                curr = curr->tp;
            }
            if (!curr) {
                T->tl = root;
                root->tp = T;
                largestNode = T;
                root = T;
            } else {
                T->tp = curr;
                pnode tmp = curr->tr;
                curr->tr = T;
                T->tl = tmp;
                tmp->tp = T;
                largestNode = T;
            }
        }
    }
}
void BuildNaively(pnode& root, int* a, int n) {
    for (int i = 0; i < n; ++i) {
        pnode T = new Node();
        T->key = a[i];
        root = Merge(root, T);
    }
}
void Clear(pnode& root) {
    if (!root) {
        return;
    }
    Clear(root->tl);
    delete root;
    Clear(root->tr);
}
