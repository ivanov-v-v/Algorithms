void Example1() {
    // Check whether there is any subset of elements that sum up to S.
    // Example of DP on subset.
    vector<int> answ(20);
    cout << fixed << setprecision(10);
    int n; cin >> n;
    for (int i = 0; i< n; i++) {
        cin >> a[i];
    }
    ll s;
    cin >> s;
    // Naive: for every mask, check every bit and construct a subset
    // for (int mask = 0; mask < (1<<n); mask++) {
    //     ll currSum = 0;
    //     for (int bit = 0; bit < n; bit++) {
    //         if (checkbit(mask, bit) == 1) {
    //             currSum += a[bit];
    //         }
    //     }
    //     if (currSum == s) {
    //         for (int bit = 0; bit < n; bit++) {
    //             if (checkbit(mask, bit) == 1) {
    //                 cout << bit+1 << " ";
    //             }
    //         }
    //         cout << "\n";
    //         return;
    //     }
    // }
    // Optimized: use dynamic programming.
    // Store index of lowest bit for every mask
    // and recalculate subset sum using this information.
    vector<ll> d(1<<n);
    vector<int> lb(1<<n);
    for (int mask = 1; mask < (1<<n); i++) {
        int k = lb[mask] = (i&1) ? 0 : lb[mask>>1]+1;
        d[mask] = d[mask^(1<<k)]+a[k];
        if (d[mask] == s) {
            cout << "YES" << endl;
            return;
        }
    }
}

void Example2(){
    //TIMUS 1152
    vector<int> moves(101);
    vector<int> a(101);
    int n; cin >> n;
    in_range(i, 0, n) cin >> a[i];
    moves[0] = 7;   //submasks to bitwise AND with
    for (int i = 1; i < n; i++) {
        moves[i] = moves[i-1]<<1;
        if (moves[i] >= (1<<n)) {
            moves[i]++; //add lowest bit
        }
    }
    vector<int> d(1<<n, INT_MAX);
    vector<int> sum(1<<n);
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int bit = 0; bit < n; bit++) {
            if (checkbit(mask, bit)) {
                s[mask] += a[bit];
            }
        }
        for (int i = 0; i < n; i++) {
            int to = mask & ~moves[i];
            if (to == mask) continue;
            d[to] = min(d[mask], d[to]+sum[to]);
        }
    }
    cout << d[(1<<n)-1] << endl;
}

void Example3(){
    // Hamiltonian path of minimal weight
    auto G = tensor<int>(20, 20);
    for (auto &row : G) fill(all(row), 1e7);
    int n; cin >> n;
    in_range(y, 0, n) {
        in_range(x, 0, n) {
            cin >> G[y][x];
        }
    }
    // State: subset of visited vertices
    //        and index of last vertex visited
    // Memory overhead: N*(1<<N)
    auto dp = tensor<int>(1<<16, 16);
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int k = 0; k < n; k++) {
            if (!checkbit(mask, k)) continue;
            if (mask == (1 << k)) {
                dp[mask][k] = 0;
            } else {
                int to = mask ^ (1<<k);
                dp[mask][k] = INF;
                for (int j = 0; j < n; j++) {
                    if (G[j][k] && checkbit(to, j)) {
                        // iterate over all the vertices
                        // and try to go over the edje (j, k)
                        dp[mask][k] = min(dp[mask][k], dp[to][j]+G[j][k]);
                    }
                }
            }
        }
    }
    print(*min_element(all(dp[(1<<n)-1])));
    // Upgrade to Min Hamiltonian Cycle:
    // Store additional state dimension: first vertex
}

void Example4(){
    // Check whether there is any Hamiltonian Cycle
    // Naive
    // auto G = tensor<bool>(20, 20);
    // for (auto &row : G) fill(all(row), 1e7);
    // int n; cin >> n;
    // in_range(y, 0, n) {
    //     in_range(x, 0, n) {
    //         cin >> G[y][x];
    //     }
    // }
    // auto dp = tensor<int>(1<<16, 16);
    // for (int mask = 1; mask < (1<<n); mask++) {
    //     for (int k = 0; k < n; k++) {
    //         if (!checkbit(mask, k)) continue;
    //         if (mask == (1 << k)) {
    //             dp[mask][k] = 0;
    //         } else {
    //             int to = mask ^ (1<<k);
    //             for (int j = 0; j < n; j++) {
    //                 if (G[j][k] && checkbit(to, j)) {
    //                     // iterate over all the vertices
    //                     // and try to go over the edje (j, k)
    //                     dp[mask][k] |= dp[to][j];
    //                 }
    //             }
    //         }
    //     }
    // }
    // Optimized: instead of storing two-dimensional array
    // dp[mask] stores bitmask where true is written in bits
    // we can end up our way in given mask
    // bitmask DP stores... bitmask
    auto G = tensor<int>(20, 20);
    for (auto &row : G) fill(all(row), 1e7);
    vector<int> previousVertices(20);
    int n; cin >> n;
    in_range(y, 0, n) {
        in_range(x, 0, n) {
            cin >> G[y][x];
        }
        if (G[j][i]) {
            // previous_vertices[i] -- subset of vertices j
            // we can transition to i from
            previousVertices[i] |= (1<<j);
        }
    }

    auto dp = tensor<int>(1<<16, 16);
    // состояние -- маска посещённых
    // значение -- маска конечных
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int k = 0; k < n; k++) {
            if (!checkbit(mask, k)) continue;
            if (mask == (1 << k)) {
                dp[mask] = (1<<k);
            } else {
                int to = mask ^ (1<<k);
                // маска тех вершин, в которых мы можем закончить путь в to
                int endVertices = dp[to];
                // проверка: можем ли мы из to посетить маску mask
                // так, чтобы прийти в вершину k
                if (endVertices & previousVertices[k]) { // ключевой оптимайз
                    // если она содержит вершины, из которых мы можем перейти в k
                    dp[mask] |= (1<<k);
                }
            }
        }
    }
    print(dp[(1<<n)-1]?"YES":"NO");
}

void Example5() {
    // Meet In The Middle
    // Example: NSUM
    // O (N 2^(N.2))
    vector<int> a(40); // Prev. solution gives O(1<<40)
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mid = n/2;
    // рекурсивно получить все возможные суммы
    vector<ll> v;
    function<void(int, ll)> go = [&](int curr, ll sum = 0) {
        if (curr < 0) {
            v.pb(sum);
            return;
        } else {
            go (curr-1, sum);
            go (curr-1, sum+a[curr]);
        }
    };
    go (mid-1);
    auto leftV = v;
    v.clear();
    reverse(all(a));
    v.clear();
    go (n-mid-1);
    auto rightV = v;
    DBN(leftV, v);
    sort(all(leftV));
    // отсортируем один из векторов
    // и будем перебирать элементы второго
    // бинпоиском подыскивая им пару в первом
    for (ll t : v) {
        ll x = s-t;
        if (binary_search(all(leftV), x)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

void Example6() {
    // Пример подхода MiM -- "Плюсы и звёздочки 2"
    // SEERC 1/4 2014
    // Напрашивается наивное решение, но ограничения в два раза
    // больше, чем нужно => Пишем meet in the middle.
    // Из-за наличия знаков умножения,
    // правая и левая половины не независимы
    // так что уместно перебрать ответ на всех префиксах
    // и на всех суффиксах.
    // O(N^2 2^(N/2))
}

void Example7(){
    // Динамика по профилю
    // Задача "Паркет": ориентация -- по горизонтали
    // Идейная часть -- хранить последний слой
    // В этой задаче -- столбец
    // в котором в ячейке записана единица,
    // если она пересекает какую-то плитку
    // иначе -- ноль
    // dp[n][mask]
    // переходы: dp[n-1][prev] -> dp[n][mask]
}

int mid;
vector<ll> sum;
int diff;
int aim;

void go (int curr, ll sum, ll prod) {
    if (sum + prod > aim) {
        return;
    }
    s[curr].push_back(sum+prod);
    if (curr == mid) return;
    go(curr+diff, sum+prod, a[curr+diff]);
    go(curr+diff, sum, prod*a[curr+diff]);
}

}
