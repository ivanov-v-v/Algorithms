int rows, cols;
vector<vector<int>> height;
int n, m;
vector<vector<pii>> G;
inline int lin(int row, int col) { return row*cols + col + 1; }
inline bool correct(int y, int x) { return y >= 0 && y < rows && x >= 0 && x < cols; }

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

vector<int> d;
vector<char> used;

int main(){
//    fastIO();
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    cin >> rows >> cols;
    height = tensor<int>(rows, cols);
    cin >> height;
    n = rows*cols+1;
    G.resize(n);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int from = lin(y, x);
            if (!height[y][x] || y == 0 || y == rows-1 || x == 0 || x == cols-1) {
                G[0].emplace_back(from, height[y][x]), m++;
                G[from].emplace_back(0, height[y][x]), m++;
            }
            for (int i = 0; i < 4; i++) {
                int ny = y+dy[i],
                    nx = x+dx[i],
                    to = lin(ny, nx);
                if (correct(ny, nx)) {
                    G[to].emplace_back(from, max(height[ny][nx], height[y][x])), m++;
                    G[from].emplace_back(to, max(height[ny][nx], height[y][x])), m++;
                }
            }
        }
    }
    used.resize(n);
    d = vector<int>(n, INF);
    d[0] = 0;
    set<pii> pq;
    pq.insert({d[0], 0});
    while (!pq.empty()) {
        int from = pq.begin()->scd,
            opt_h = pq.begin()->fst;
        pq.erase(pq.begin());
        used[from] = 1;
        for (int i = 0; i < G[from].size(); i++) {
            int to = G[from][i].fst,
                edge_h = G[from][i].scd;
            if (used[to]) continue;
            if (d[to] > max(opt_h, edge_h)) {
                pq.erase({d[to], to});
                d[to] = max(opt_h, edge_h);
                pq.insert({d[to], to});
            }
        }
    }
    auto water_level = tensor<int>(rows, cols);
    auto answ = tensor<int>(rows, cols);
    for (int i = 1; i < n; i++) {
        int x = (i-1)%cols, y = (i-1-x)/cols;
        water_level[y][x] = max(0, d[i] - height[y][x]);
        answ[y][x] = d[i];
    }
    print(answ);
    print(water_level);
    return 0;
}
