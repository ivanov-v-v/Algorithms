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
