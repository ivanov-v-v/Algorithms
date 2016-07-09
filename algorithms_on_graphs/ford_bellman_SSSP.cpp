int n, m;
vector<vector<int>> G;
vector<int> d;
struct edge { int from, to, cost; };
vector<edge> edges;
void read_graph(bool zero_indexed = 1, bool directed = 0) {
    cin >> n >> m;
    d.resize(n); G.resize(n);
    edges.reserve((directed ? 1 : 2) * m);
    for (int i = 0, from, to, cost; i < m; i++) {
        cin >> from >> to >> cost;
        if (zero_indexed) from--, to--;
        G[from].pb(to);
        edges.pb({from, to, cost});
        if (!directed) {
            G[to].pb(from);
            edges.pb({to, from, cost});
        }
    }
    if (!directed) m *= 2;
}
void ford_bellman(int v) {
    fill(all(d), INF);
    d[v] = 0;
    int i = 0;
    for (; i < n; i++) {
        bool changed = false;
        for (int j = 0; j < m; j++) {
            if (d[edges[j].from] < INF) {
                edge &e = edges[j];
                if (d[e.to] > d[e.from]+e.cost) {
                    d[e.to] = d[e.from]+e.cost;
                    changed = true;
                }
            }
        }
        if (!changed) { break; }
    }
    if (i == n) { cout << "NEGATIVE CYCLE ALARM\n"; }
}

int main(){
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    read_graph();
    ford_bellman(0);
    for (auto el : d) cout << el << " ";
    return 0;
}
