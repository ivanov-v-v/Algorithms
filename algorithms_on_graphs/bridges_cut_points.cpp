vector<vector<int>> G;
vector<int> tin, fup;
vector<bool> used;
int timer = 0;

inline void IS_CUTPOINT(int v) {
    cout << "CUTPOINT FOUND: " << v+1 << "\n";
}
void find_cut_points(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (int i = 0; i < G[v].size(); i++) {
        int to = G[v][i];
        if (to == p) continue;
        if (used[to]) { // back edge
            fup[v] = min(fup[v], tin[to]);
        } else { // dfs edge
            find_cut_points(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1) {
                IS_CUTPOINT(v);
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        IS_CUTPOINT(v);
    }
}
inline void IS_BRIDGE(int u, int v) {
    cout << "BRIDGE FOUND: (" << u+1 << " --> " << v+1 << ")\n";
}
void find_bridges(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (auto &to : G[v]) {
        if (to == p) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            find_bridges(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                IS_BRIDGE(v, to);
            }
        }
    }
}

int main(){
//    fastIO();
    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int n, m;
    cin >> n >> m;
    G.resize(n);
    used.resize(n);
    tin.resize(n);
    fup.resize(n);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b; a--, b--;
        G[a].pb(b); G[b].pb(a);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) find_cut_points(i);
    }
    fill(all(used), false);
    fill(all(tin), 0);
    fill(all(fup), 0);
    timer = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) find_bridges(i);
    }
    return 0;
}
