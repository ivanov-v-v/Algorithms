template<typename T>
class segment_tree {
private:
    int MAXN;
    function<T(T, T)> op;
    T id;
    vector<T> t;

    void _build_tree(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr)>>1;
            _build_tree(a, v*2, tl, tm);
            _build_tree(a, v*2+1, tm+1, tr);
            t[v] = op(t[v*2], t[v*2+1]);
        }
    }

    void _update_position(int v, int tl, int tr, int pos, const T& val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr)>>1;
            if (pos <= tm)  _update_position(v*2, tl, tm, pos, val);
            else            _update_position(v*2+1, tm+1, tr, pos, val);
            t[v] = op(t[v*2], t[v*2+1]);
        }
    }

    T _fold_range(int v, int tl, int tr, int l, int r) const {
        if (l > r) return id;
        if (l == tl && tr == r) {
            return t[v];
        } else {
            int tm = (tl + tr)>>1;
            return op(_fold_range(v*2, tl, tm, l, min(tm, r)),
                        _fold_range(v*2+1, tm+1, tr, max(l, tm+1), r));
        }
    }

public:
    segment_tree(int SIZE, function<T(T, T)> bin_op, const T& op_id) {
        MAXN = SIZE;
        id = op_id;
        op = bin_op;
        t.resize(4*SIZE+1);
    }
    inline void build_tree(const vector<T>& a) {
        assert(a.size() == MAXN);
        _build_tree(a, 1, 0, MAXN-1);
    }
    inline void update_position(int pos, const T& val) {
        assert(0 <= pos && pos < MAXN);
        _update_position(1, 0, MAXN-1, pos, val);
    }
    inline T fold_range(int l, int r) const {
        assert(0 <= l && l <= r && r < MAXN);
        return _fold_range(1, 0, MAXN-1, l, r);
    }
};
