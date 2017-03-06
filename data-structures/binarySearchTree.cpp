template <typename T>
class BST {
private:
    struct Node {
        T value;
        Node *left, *right, *parent;
        Node() {
            value = 0;
            left = right = parent = nullptr;
        }
        Node (const T& key) {
            value = key;
            left = right = parent = nullptr;
        }
    };
    Node* find(Node* root, const T& key) const {
        if (!root) {
            return root;
        }
        if (key < root->value) {
            return find(root->left, key);
        } else if (key == root->value) {
            return root;
        } else {
            return find(root->right, key);
        }
    }
    void insert(Node*& root, const T& key) {
        if (!root) {
            root = new Node(key);
            return;
        }
        if (key < root->value) {
            if (root->left) {
                insert(root->left, key);
            } else {
                root->left = new Node(key);
                root->left->parent = root;
                return;
            }
        } else if (key == root->value) {
            return;
        } else {
            if (root->right) {
                insert(root->right, key);
            } else {
                root->right = new Node(key);
                root->right->parent = root;
                return;
            }
        }
    }
    Node* findMinimum(Node* root) const {
        if (root) {
            while (root->left) {
                root = root->left;
            }
        }
        return root;
    }
    Node* findMaximum(Node* root) const {
        if (root) {
            while (root->right) {
                root = root->right;
            }
        }
        return root;
    }
    Node* erase(Node* root, const T& key) {
        if (!root) {
            return root;
        }
        if (key < root->value) {
            root->left = erase(root->left, key);
            if (root->left) {
                root->left->parent = root;
            }
        } else if (key > root->value) {
            root->right = erase(root->right, key);
            if (root->right) {
                root->right->parent = root;
            }
        } else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->right) {
                Node* leftChild = root->left;
                delete root;
                return root = leftChild;
            } else if (!root->left) {
                Node* rightChild = root->right;
                delete root;
                return root = rightChild;
            } else {
                Node* newRoot = findMinimum(root->right);
                root->value = newRoot->value;
                root->right = erase(root->right, newRoot->value);
                return root;
            }
        }
    }
    void clean(Node* root) {
        if (!root) {
            return;
        }
        clean(root->left);
        clean(root->right);
        delete root;
        return;
    }
    void inorderTraversal(Node* root) const {
        if (!root) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
    Node *root;
public:
    BST(): root(nullptr) {}
    ~BST() {
        clean(root);
    }
    void insert(const T& key) {
        insert(root, key);
    }
    void erase(const T& key) {
        root = erase(root, key);
    }
    T getMinimum() const {
        return findMinimum(root)->value;
    }
    T extractMinimum() {
        T minVal = findMinimum(root)->value;
        root = erase(root, minVal);
        return minVal;
    }
    T predecessor(const T& key) const {
        Node *curr = root;
        T prev = numeric_limits<T>::min();
        while (curr && curr->value != key) {
            if (key < curr->value) {
                curr = curr->left;
            } else {
                prev = max(prev, curr->value);
                curr = curr->right;
            }
        }
        Node* subMax = findMaximum(curr->left);
        if (subMax) {
            prev = max(prev, subMax->value);
        }
        return prev;
    }
    T successor(const T& key) const {
        Node *curr = root;
        T next = numeric_limits<T>::max();
        while (curr && curr->value != key) {
            if (key < curr->value) {
                next = min(next, curr->value);
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        Node* subMin = findMinimum(curr->right);
        if (subMin) {
            next = min(next, subMin->value);
        }
        return next;
    }
    void inorderTraversal() const {
        inorderTraversal(root);
    }
};
