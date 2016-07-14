template<typename T>
class segment_tree_2D {
private:
    int ROWS, COLS;
    function<T(T, T)> op;
    T id;
    vector<vector<T>> t;

    void _build_y(const vector<vector<T>>& data, int vy, int y_tl, int y_tr) {
        if (y_tl != y_tr) {
            int y_tm = (y_tl + y_tr)>>1;
            _build_y(data, vy*2, y_tl, y_tm);
            _build_y(data, vy*2+1, y_tm+1, y_tr);
        }
        _build_x(data, vy, y_tl, y_tr, 1, 0, COLS-1);
    }
    void _build_x(const vector<vector<T>>& data, int vy, int y_tl, int y_tr, int vx, int x_tl, int x_tr) {
        if (x_tl == x_tr) {
            if (y_tl == y_tr) {
                t[vy][vx] = data[y_tl][y_tr];
            } else {
                t[vy][vx] = op(t[vy*2][vx], t[vy*2+1][vx]);
            }
        } else {
            int x_tm = (x_tl + x_tr)>>1;
            _build_x(vy, y_tl, y_tr, vx*2, x_tl, x_tm);
            _build_x(vy, y_tl, y_tr, vx*2+1, x_tm+1, x_tr);
            t[vy][vx] = op(t[vy][vx*2], t[vy][vx*2+1]);
        }
    }

    void _set_y(int vy, int y_tl, int y_tr, int y, int x, const T& val) {
        if (y_tl != y_tr) {
            int y_tm = (y_tl + y_tr)>>1;
            if (y <= y_tm) {
                _set_y(vy*2, y_tl, y_tm, y, x, val);
            } else {
                _set_y(vy*2+1, y_tm+1, y_tr, y, x, val);
            }
        }
        _set_x(vy, y_tl, y_tr, 1, 0, COLS-1, y, x, val);
    }
    void _set_x(int vy, int y_tl, int y_tr, int vx, int x_tl, int x_tr, int y, int x, const T& val) {
        if (x_tl == x_tr) {
            if (y_tl == y_tr) {
                t[vy][vx] = val;
            } else {
                t[vy][vx] = op(t[vy*2][vx], t[vy*2+1][vx]);
            }
        } else {
            int x_tm = (x_tl + x_tr)>>1;
            if (x <= x_tm) {
                _set_x(vy, y_tl, y_tr, vx*2, x_tl, x_tm, y, x, val);
            } else {
                _set_x(vy, y_tl, y_tr, vx*2+1, x_tm+1, x_tr, y, x, val);
            }
            t[vy][vx] = op(t[vy][vx*2], t[vy][vx*2+1]);
        }
    }

    T _fold_y(int vy, int y_tl, int y_tr, int ly, int ry, int lx, int rx) {
        if (ly > ry) return id;
        if (ly == y_tl && y_tr == ry) {
            return _fold_x(vy, y_tl, y_tr, 1, 0, COLS-1, ly, ry, lx, rx);
        } else {
            int y_tm = (y_tl + y_tr)>>1;
            return op(_fold_y(vy*2, y_tl, y_tm, ly, min(y_tm, ry), lx, rx),
                        _fold_y(vy*2+1, y_tm+1, y_tr, max(ly, y_tm+1), ry, lx, rx));
        }
    }
    T _fold_x(int vy, int y_tl, int y_tr, int vx, int x_tl, int x_tr, int ly, int ry, int lx, int rx) {
        if (lx > rx) return id;
        if (lx == x_tl && x_tr == rx) {
            return t[vy][vx];
        } else {
            int x_tm = (x_tl + x_tr);
            return op(_fold_x(vy, y_tl, y_tr, vx*2, x_tl, x_tm, ly, ry, lx, min(x_tm, rx)),
                    _fold_x(vy, y_tl, y_tr, vx*2+1, x_tm+1, x_tr, ly, ry, max(lx, x_tm+1), rx));
        }
    }

public:
    segment_tree_2D(int rows, int cols, function<T(T, T)> bin_op, const T& op_id) {
        ROWS = rows, COLS = cols;
        t = tensor<T>(4*ROWS+1, 4*COLS+1);
        op = bin_op;
        id = op_id;
    }

    inline void build(const vector<vector<T>>& data) {
        _build_y(data, 1, 0, ROWS-1);
    };
    inline void set_cell(int y, int x, const T& val) {
        _set_y(1, 0, ROWS-1, y, x, val);
    }
    inline T fold_range(int ly, int ry, int lx, int rx) {
        return _fold_y(1, 0, ROWS-1, ly, ry, lx, rx);
    }
};
