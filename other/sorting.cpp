template<typename T>
void selection_sort(vector<T>& a) {
    int n = a.size();
//    for (int i = 0; i < n; i++) {
//        T min_el = numeric_limits<T>::max();
//        int min_id = i;
//        for (int j = i; j < n; j++) {
//            if (a[j] < min_el) {
//                min_el = a[j];
//                min_id = j;
//            }
//        }
//        swap(a[i], a[min_id]);
//    }
    for (int i = 0; i < n; i++) {
        swap(a[i], a[min_element(begin(a)+i, end(a))-begin(a)]);
    }
}

template<typename T>
void insertion_sort(vector<T>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int id = i;
        for (int j = i-1; j >= 0 && a[j] > a[id]; j--) {
            swap(a[j], a[id]);
            id = j;
        }
    }
}

template<typename T>
void merge(vector<T>& a, int l, int m, int r) {
    int lp = l, rp = m;
    int len = r-l+1;
    vector<T> x(len);
    for (int i = 0; i < len; i++) {
        x[i] =  lp == m       ? a[rp++] :
                rp == r       ? a[lp++] :
                a[lp] < a[rp] ? a[lp++] :
                a[rp++];
    }
    for (int i = 0; i < len; i++) {
        a[l+i] = x[i];
    }
}

template<typename T>
void merge_sort(vector<T>& a, int l, int r) {
    if (r-l < 2) return;
    int m = (l+r)/2;
    merge_sort(a, l, m);
    merge_sort(a, m, r);
    merge(a, l, m, r);
}

template<typename T>
void merge(T* a, int m, int n) {
    int l = 0, r = m;
    T* x = (T*)malloc(n*sizeof(T));
    for (int i = 0; i < n; i++) {
        x[i] = l == m       ? a[r++] :
                r == n      ? a[l++] :
                a[l] < a[r] ? a[l++] :
                a[r++];
    }
    copy(x, x+n, a);
    free(x);
}

template<typename T>
void merge_sort(T* a, int n) {
    if (n < 2) return;
    int m = n/2;
    merge_sort(a, m);
    merge_sort(a+m, n-m);
    merge(a, m, n);
}

template<typename T>
int partition(vector<T>& a, int lo, int hi) {
    T pivot = a[hi];
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[hi]);
    return i;
}

template<typename T>
void quick_sort(vector<T>& a, int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quick_sort(a, lo, p-1);
        quick_sort(a, p+1, hi);
    }
}

template<typename T>
void bubble_sort(vector<T>& a) {
    bool has_changed = false;
    int i = 0, n = a.size();
    do {
        has_changed = false;
        for (int j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                has_changed = true;
            }
        }
        i++;
    } while (has_changed);
}

template<typename T>
class heap{
private:
    vector<T> tree;
    int lastn = 1;
    void swim(int v) {
        while (v != 1 && tree[v] > tree[v/2]) {
            swap(tree[v], tree[v/2]);
            v /= 2;
        }
    }
    void sink(int v) {
        while (2*v <= lastn) {
            int id = 2*v;
            if (id < lastn && tree[id] < tree[id+1]) id++;
            if (tree[v] >= tree[id]) break;
            swap(tree[v], tree[id]);
            v = id;
        }
    }
public:
    heap() {}
    heap(const vector<T>& data) {
        build_heap(data);
    }
    bool is_empty() { return lastn = 1; }
    void build_heap(const vector<T>& data) {
        tree = vector<T>(2*data.size()+2);
        for (int i = 0; i < data.size(); i++) {
            insert(data[i]);
        }
    }
    void insert(const T& val) {
        if (lastn+1 == tree.size()) {
            vector<T> ntree (tree.size()*2);
            copy(all(tree), begin(ntree));
            tree = ntree;
        }
        tree[lastn] = val;
        lastn++;
        swim(lastn-1);
    }
    inline T peek() const { return tree[1]; }
    inline T pop() {
        T root = tree[1];
        swap(tree[1], tree[lastn-1]);
        tree[lastn-1] = 0;
        lastn--;
        sink(1);
        return root;
    }
};

template<typename T>
heap<T> heapify(const vector<T>& data) {
    heap<T> res(data);
    return res;
}

template<typename T>
void heap_sort(vector<T>& data) {
    heap<T> sorting_heap = heapify(data);
    int n = data.size();
    for (int i = n-1; i >= 0; i--) {
        data[i] = sorting_heap.pop();
    }
}

int main(){
    srand(time(0));
    int n; cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = rand()%100;
    }
    heap_sort(data);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    } cout << "\n";
    return 0;
}
