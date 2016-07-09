int n, m;
vector<vector<pii>> G;
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
        G[from].pb({to, cost});
        edges.pb({from, to, cost});
        if (!directed) {
            G[to].pb({from, cost});
            edges.pb({to, from, cost});
        }
    }
    if (!directed) m *= 2;
}
//O(N^2 + M)
void dijkstra_1(int v) {
    fill(all(d), INF);
    vector<char> used(n);
    d[v] = 0;
    used[v] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (u == -1 || d[j] < d[u])) {
                u = j;
            }
        }
        if (d[u] == INF) break;
        used[u] = 1;
        for (int j = 0; j < G[u].size(); j++) {
            int to = G[u][i].fst,
                len = G[u][i].scd;
            if (!used[to] && d[to] < d[u]+len) {
                d[to] = d[u]+len;
            }
        }
    }
}
//O(M log N)
void dijkstra_2(int v) {
    fill(all(d), INF);
    vector<char> used(n);
    d[v] = 0;
    set<pii> pq;
    pq.insert({d[v], v});
    while (!pq.empty()) {
        int from = pq.begin()->scd;
        pq.erase(pq.begin());
        used[from] = 1;
        for (auto edge : G[from]) {
            int to = edge.fst,
                len = edge.scd;
            if (!used[to] && d[from]+len < d[to]) {
                pq.erase({d[to], to});
                d[to] = d[from] + len;
                pq.insert({d[to], to});
            }
        }
    }
}

int main(){
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    read_graph();
    dijkstra_2(0);
    for (auto el : d) cout << el << " ";
    return 0;
}
