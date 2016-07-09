int n, m;
vector<vector<int>> G;
vector<vector<int>> trG;
vector<bool> used;
vector<int> order;
vector<int> comp_id;
void read_graph(bool zero_indexed = 1) {
    cin >> n >> m;
    used.resize(n);
    G.resize(n); trG.resize(n);
    for (int i = 0, from, to; i < m; i++) {
        cin >> from >> to;
        if (zero_indexed) {
            from--, to--;
        }
        G[from].pb(to);
        trG[to].pb(from);
    }
}
void top_sort(int v) {
    used[v] = true;
    for (auto &to : G[v]) {
        if (!used[to]) {
            top_sort(to);
        }
    }
    order.pb(v);
}
int extract_components() {
    int comp_cnt = 0;
    comp_id.resize(n);
    function<void(int)> dfs = [&](int v){
        comp_id[v] = comp_cnt;
        for (auto &to : trG[v]) {
            if (!comp_id[to]) dfs(to);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!comp_id[i]) {
            comp_cnt++;
            dfs(i);
        }
    }
    return comp_cnt;
}

int main(){
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    read_graph();
    print(extract_components());
    print(comp_id);
    return 0;
}
