#include <bits/stdc++.h>
using namespace std;

long double M; int N;
int cnt = 0;
void go(int a, int b, int c, int d) {
    if (depth > N) return;
    int nom = a+c;
    int denom = b+d;
    if (denom > N) return;
    if (nom <= M*denom) {
        go(nom, denom, c, d, depth+1);
        cnt++;
    }
    go(a, b, nom, denom, depth+1);
}

int main(){
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    cin >> M >> N;
    go(0, 1, 1, 0);
    cout << cnt << endl;
    return 0;
}
