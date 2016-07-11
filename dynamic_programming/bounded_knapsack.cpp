    int S, N;
    cin >> S >> N;
    vector<ll> w(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
    }
    auto d = tensor<ll>(S+1, N+1);
    for (int s = 1; s <= S; s++) {
        for (int i = 1; i <= N; i++) {
            d[s][i] = d[s][i-1];
            if (w[i] <= s) {
                d[s][i] = max(d[s][i], d[s-w[i]][i-1]+w[i]);
            }
        }
    }
    print(d[S][N]);
