#include <bits/stdc++.h>
using namespace std;

const int MAXN = int(1e5);  //max array size
int n;              //array size
int t[2*MAXN];      //segment tree

void build(){   //build the tree. Initial values are stored in continuos order in range [n; 2*n)
    for(int i = n-1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value){  //single-element modification
    for(t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

//important note: query(l, r) ~ query [l, r) (in mathematical notation)
int query(int l, int r){    //sum range-query, though supports any commutative monoidal operation
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1) res += t[l++];  //if l is odd, it is a right child. Then, it is not yet included in answer.
        if(r&1) res += t[--r];  //same thing with r
    }
    return res;
}

int main()
{
//    ios::sync_with_stdio(false);
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    return !true && !false;
}
