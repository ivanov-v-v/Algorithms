// Given a static colored rooted tree,
// calculate number of distinct colors in each subtree.

const int MAXN = 1e6;
vector<int> G[MAXN];    // tree (assume that it is already sorted topologically)
int c[MAXN];            // colors
int used[MAXN], cc = 1; // integer labeling

// construct Euler tour:
// run a dfs on a topologically sorted tree
// and store for each vertex such information:
// tin   -- moment of first visit,
// tout  -- moment of last visit.
// At the same time, maintain two arrays:
// depth -- distance from root to active vertex,
// id    -- index of active vertex.
// Push a new entry to both of those
// every time the active vertex changes.

int tin[MAXN], tout[MAXN], T = 0;
vector<int> depth, id;
void init_lcp(int u, int d = 0) {
    used[u] = cc;
    tin[u] = T++;
    depth.pb(d);
    id.pb(u);
    if (G[u].empty()) {
        id.pb(u);
        depth.pb(d);
        tout[u] = T++;
    } else {
        for (auto v : G[u]) {
            if (used[v] != cc) {
                init_lcp(v, d+1);
                id.pb(u);
                depth.pb(d);
                tout[u] = T++;
            }
        }
    }
}

// Reduce LCA to RMQ using sparse-table on Euler tour:
// two vertices u and v describe a segment in dfs traversal,
// corresponding to the time interval needed to traverse
// subtrees of both u and v. As we have depth-array,
// we can find the smallest element in that segment
// and tell an index of the corresponding vertex, LCA(u, v).

// 1. Construct sparse table
vector<vector<int>> st;
void build() {
    int m = binlog(T);
    for (int i = 0; i < T; i++) {
        st[0][i] = i;
    }
    for (int k = 1; k <= m; k++) {
        for (int i = 0; i+(1<<k)-1 < T; i++) {
            int l = st[k-1][i], r = st[k-1][i+(1<<(k-1))];
            st[k][i] = depth[l] <= depth[r] ? l : r;
        }
    }
}
inline void init_sparse_table() {
    int k = binlog(T);
    st = tensor<int>(k+1, T);
    build();
}
int get(int l, int r) {
    int k = binlog(r-l+1);
    int lp = st[k][l], rp = st[k][r-(1<<k)+1];
    return depth[lp] <= depth[rp] ? lp : rp;
}
// 2. Get LCA in O(1) (online)
int lca(int u, int v) {
    return id[get(min(tin[u], tin[v]), max(tout[u], tout[v]))];
}

// Calculate the answer using Hui's algorithm:
// http://goo.gl/fKtLq9
// For a given node p,
// consider all such pairs (u, v)
// from a subtree of p, that lca(u, v) = p
// and color[u] == color[v].
// If there are k > 0 of them,
// as their contribution to answer in p
// must be 1, we can notice
// that 1 = k - (k-1),
// so we can simply increment an answer
// in u and v once, and decrement an
// answer in p (k-1) times.
// After summing up the answers
// in subtrees, we will get the final answer for parent.
// To do so, as our tree is topologically sorted already,
// we can for every v find an already visited u with the same color,
// if any, and then update the answers: answ[v]++, answ[lca(u, v)]--.
// Therefore, we can solve the original problem in dfs time complexity.
int last[MAXN];
int dp[MAXN];
void init_Hyui() {
    fill(last, last+MAXN, -1);
}
void dfs(int u) {
    used[u] = cc;
    if (last[c[u]] != -1) {
        int v = last[c[u]];
        int p = lca(u, v);
        dp[p]--;
    }
    last[c[u]] = u;
    dp[u]++;
    for (auto v : G[u]) {
        if (used[v] != cc) {
            dfs(v);
            dp[u] += dp[v];
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].pb(v);
    }
    init_lcp(0); cc++;
    init_sparse_table();
    init_Hyui();
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << i+1 << ": " << dp[i] << "\n";
    }
    return 0;
}
