// SOME FUNCTIONAL NEEDS TO BE TESTED, BEWARE

struct SplayTree {
    SplayTree *left, *right, *parent;
    int key;
    SplayTree() = default; //{
//        key = numeric_limits<int>::min();
//        left = right = parent = nullptr;
//    }
    explicit SplayTree(int val){
        key = val;
        left = right = parent = nullptr;
    }
};
void traverseTree(SplayTree* root, unsigned depth = 0) {
    if (!root) {
        return;
    }
    traverseTree(root->left, depth + 1);
    for (size_t i = 0; i < depth; ++i) {
        cout << "\t";
    }
    cout << (!root->parent ? "O" : (root == root->parent->left ? "L" : "R")) << " ";
    cout << root->key << "\n";
    traverseTree(root->right, depth + 1);
}
void rotateLeft(SplayTree*& X) {
    if (!X || !X->parent) {
        throw std::logic_error("LR: something has gone wrong.");
    }
    SplayTree *P = X->parent,
        *A = X->left,
        *B = X->right,
        *C = P->right;

    X->left = A; if (A) { A->parent = X; }
    X->right = P;
    X->parent = P->parent;
    if (P->parent) {
        if (P == P->parent->left) {
            P->parent->left = X;
        } else {
            P->parent->right = X;
        }
    }

    P->left = B; if (B) { B->parent = P; }
    P->right = C; if (C) { C->parent = P; }
    P->parent = X;
    return;
}
void rotateRight(SplayTree*& X) {
    if (!X || !X->parent) {
        throw std::logic_error("RR: something has gone wrong.");
    }
    SplayTree *P = X->parent,
            *A = P->left,
            *B = X->left,
            *C = X->right;
    X->left = P,
    X->right = C; if (C) { C->parent = X; }
    X->parent = P->parent;
    if (P->parent) {
        if (P == P->parent->left) {
            P->parent->left = X;
        } else {
            P->parent->right = X;
        }
    }

    P->left = A; if (A) { A->parent = P; }
    P->right = B; if (B) { B->parent = P; }
    P->parent = X;
    return;
}
void Splay(SplayTree*& X) {
    if (!X) {
        return;
    }
    while (X->parent) {
        SplayTree* P = X->parent;
        if (!P->parent) { // zig
            if (X == P->left) {
                rotateLeft(X);
            } else { // also zig
                rotateRight(X);
            }
        } else {
            SplayTree *GP = P->parent;
            if (P == GP->left) {
                if (X == P->left) { // zig-zig
                    rotateLeft(P);
                    rotateLeft(X);
                } else { // zig-zag
                    rotateRight(X);
                    rotateLeft(X);
                }
            } else {
                if (X == P->right) { // zig-zig
                    rotateRight(P);
                    rotateRight(X);
                } else { // zig-zag
                    rotateLeft(X);
                    rotateRight(X);
                }
            }
        }
    }
}
int getMaximum(SplayTree*& root) {
    if (!root) {
        throw std::logic_error("Empty tree.");
    }
    SplayTree* curr = root;
    while (curr->right) {
        curr = curr->right;
    }
    Splay(curr);
    root = curr;
    return root->key;
}
int getMinimum(SplayTree*& root) {
    if (!root) {
        throw std::logic_error("Empty tree.");
    }
    SplayTree* curr = root;
    while (curr->left) {
        curr = curr->left;
    }
    Splay(curr);
    root = curr;
    return root->key;
}
SplayTree* Merge(SplayTree*& L, SplayTree*& R) { // all keys in L <= all keys in R
    if (!L || !R) {
        return L ? L : R;
    }
    getMaximum(L);
    R->parent = L;
    L->right = R;
    return L;
}
void insertNode(SplayTree*& root, SplayTree*& node) {
    root = Merge(root, node);
}
void insertKey(SplayTree*& root, int key) {
    SplayTree* newNode = new SplayTree(key);
    insertNode(root, newNode);
}
SplayTree* Search(SplayTree*& root, int key) {
    SplayTree* curr = root, *prev;
    while (curr) {
        prev = curr;
        if (curr->key < key) {
            curr = curr->left;
        } else if (curr->key == key) {
            break;
        } else {
            curr = curr->right;
        }
    }
    if (curr) {
        Splay(curr);
        root = curr;
    } else {
        Splay(prev);
        root = prev;
    }
    return root;
}
void Split(SplayTree*& root, int key, SplayTree*& L, SplayTree*& R) {
    const int EPS1 = 1;
    Search(root, key + EPS1);
    if (root->key <= key) {
        R = root->right;
        R->parent = nullptr;
        root->right = nullptr;
        L = root;
    } else {
        L = root->left;
        L->parent = nullptr;
        root->left = nullptr;
        R = root;
    }
}
void Delete(SplayTree*& root, int key) {
    SplayTree* candidate = Search(root, key);
    if (!candidate || candidate->key != key) {
        return;
    }
    SplayTree *L = candidate->left,
        *R = candidate->right;
    if (L) { L->parent = nullptr; }
    if (R) { R->parent = nullptr; }
    root = Merge(L, R);
    return;
}
