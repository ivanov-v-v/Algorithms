int n, m;
vector<vector<int>> G;
vector<int> d, in;
vector<char> used;
void calc_dist(int v) {
    used[v] = 1;
    for (auto u : G[v]) {
        int before = d[u];
        d[u] = max(d[u], d[v]+1);
        if (d[u] > before && used[u]) {
            used[u] = false;
            calc_dist(u);
        } else if (!used[u]) calc_dist(u);
    }
}

int main(){
    cin >> n >> m;
    G.resize(n);
    d = in = vector<int>(n);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        in[b]++;
    }
    used = vector<char>(n);
    for (int v = 0; v < n; v++) {
        if (!in[v]) {
            calc_dist(v);
        }
    }
    cout << *max_element(begin(d), end(d)) << endl;
    return 0;
}
