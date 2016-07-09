template<typename T>
class fenwick_tree{
private:
    int N;
    vector<T> f;
public:
    fenwick_tree(int size) {
        N = size;
        f.resize(N);
    }
    fenwick_tree(const vector<T>& data) {
        N = data.size();
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j += j&-j) {
                f[j] += data[i];
            }
        }
    }
    T pref(int r) {
        T sum = 0;
        for (; r; r -= r&-r) {
            sum += f[r];
        }
        return sum;
    }
    T get(int l, int r) {
        return pref(r)-pref(l-1);
    }
    void upd(int i, T x) {
        T delta = x-get(i-1, i);
        for (; i < N; i += i&-i) {
            f[i] += delta;
        }
    }
};
