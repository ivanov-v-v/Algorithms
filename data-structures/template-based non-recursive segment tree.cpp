#include <bits/stdc++.h>
using namespace std;

/*
    Non-recursive implementation of segment-tree
    Guaranteed support of any monoidal operation
    Supports:
        1) Single-element modification
        2) Range queries
*/

template<typename T>
class segment_tree{
private:
    int data_size;  //initial dataset size
    T *t = nullptr; //tree, array-based
    function<T(T, T)> op;
    T id;
public:
    segment_tree(int array_size, function<T(T, T)> bin_op, T identity){
        data_size = array_size;
        t = new T[2*data_size];
        for(int i = 0; i < 2*data_size; i++) t[i] = identity;
        op = bin_op;
        id = identity;
    }
    ~segment_tree(){}

    void build(){
        for(int i = data_size-1; i > 0; i--)
            t[i] = op(t[i<<1], t[i<<1|1]);
    }
    void read_data(){
        for(int i = data_size; i < 2*data_size; i++)
            cin >> t[i];
        build();
    }
    void show_data(){
        for(int i = 0; i < 2*data_size; i++)
            cout << t[i] << " ";
        cout << endl;
    }
    void assign(int a[]){
        for(int i = 0; i < data_size; i++)
            t[i+data_size] = a[i];
        build();
    }
    void modify(int p, int value){
        for(t[p += data_size] = value; p > 1; p >>= 1)
            t[p>>1] = op(t[p], t[p^1]);
    }
    T query(int l, int r){
        T resl = id, resr = id;
        for(l += data_size, r += data_size; l < r; l >>= 1, r >>= 1){
            if(l&1) resl = op(resl, t[l++]);
            if(r&1) resr = op(t[--r], resr);
        }
        return op(resl, resr);
    }
};

int main()
{
    int n; scanf("%d", &n);
    segment_tree<double> t(n, [&](double a, double b){return a*b;}, 1.);
    t.read_data();
    cout << t.query(0, n) << endl;
    return !true && !false;
}
