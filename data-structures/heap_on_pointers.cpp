template<typename T>
class heap{
private:

    struct node{
        node *tl, *tr;
        T key;
        int cnt;
        node () {
            tl = tr = nullptr;
            key = T(0);
            cnt = 1;
        }
        node (T key_val) {
            tl = tr = nullptr;
            key = key_val;
            cnt = 1;
        }
    };
    typedef node* pnode;
    int cnt(pnode t) { return t ? t->cnt : 0; }
    void upd(pnode t) { if (t) t->cnt = 1 + cnt(t->tl) + cnt(t->tr); }

    pnode root;
    pnode merge(pnode& L, pnode& R) {
        if (!L || !R) {
            return L ? L : R;
        }
        if (L->key > R->key) {
            L->tr = merge(L->tr, R);
            upd(L); return L;
        } else {
            R->tl = merge(L, R->tl);
            upd(R); return R;
        }
    }
public:
    heap() { root = nullptr; }
    heap(pnode t) { root = t; }
    heap(const T& val) { root = new node(val); }
    template<class Iter>
    heap(Iter b, Iter e) {
        root = heapify(b, e);
    }
    inline bool is_empty() { return root == nullptr; }
    inline void insert(const T& val) { root = merge(root, new node(val)); }
    inline T pop() {
        assert(root);
        T top = root->key;
        root = merge(root->tl, root->tr);
        return top;
    }
    inline T peek() {
        assert(root);
        return root->key;
    }
    template<class Iter>
    pnode heapify(Iter b, Iter e) {
        if (b == e) return new node();
        if (e - b == 1) return new node(*b);
        Iter mid = b + (e - b)/2;
        pnode L = heapify(b, mid),
                R = heapify(mid, e);
        return merge(L, R);
    }
};

template<typename T>
void heap_sort(vector<T>& data) {
    heap<T> h(all(data));
    int n = data.size();
    for (int i = 0; i < n; i++) {
        data[n-1-i] = h.pop();
    }
}

int main(){
//    fastIO();
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand()%100;
    }
    heap_sort(a);
    print(a);
    return 0;
}
