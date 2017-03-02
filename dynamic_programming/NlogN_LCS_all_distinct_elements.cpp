pair<int, vector<int>> naiveLCS(const vector<int>& v1, const vector<int>& v2) {
    if (v1.empty() || v2.empty()) {
        return {0, vector<int>()};
    }
    int n = v1.size(), m = v2.size();
    vector<vector<int>> dp(n, vector<int>(m));
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m));
    dp[0][0] = v1[0] == v2[0];
    for (size_t i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], int(v1[i] == v2[0]));
        prev[i][0] = {i - 1, 0};
    }
    for (size_t j = 1; j < m; ++j) {
        dp[0][j] = max(dp[0][j - 1], int(v1[0] == v2[j]));
        prev[0][j] = {0, j - 1};
    }
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            if (v1[i] == v2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                prev[i][j] = {i - 1, j - 1};
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    prev[i][j] = {i - 1, j};
                } else {
                    dp[i][j] = dp[i][j - 1];
                    prev[i][j] = {i, j - 1};
                }
            }
        }
    }
    vector<int> common;
    int i = n - 1, j = m - 1;
    while (i && j) {
        if (prev[i][j] == make_pair(i - 1, j - 1)) {
            common.push_back(v1[i]);
            --i, --j;
        } else if (prev[i][j] == make_pair(i - 1, j)) {
            --i;
        } else  {
            --j;
        }
    }
    if (v1[i] == v2[j]) {
        common.push_back(v1[i]);
    }
    reverse(common.begin(), common.end());
    return {dp[n - 1][m - 1], common};
}

pair<int, vector<int>> allDistinctElementsLCS(const vector<int>& v1, const vector<int>& v2) {
    const vector<int>& A = v1.size() < v2.size() ? v2 : v1;
    const vector<int>& B = v1.size() < v2.size() ? v1 : v2;

    int n = v1.size(), m = v2.size();
    map<int, int> pos;
    for (size_t i = 0; i < n; ++i) {
        pos[A[i]] = i + 1;
    }
    vector<int> processedData;
    for (size_t i = 0; i < m; ++i) {
        int id = pos[B[i]];
        processedData.push_back(id ? id - 1 : -1);
    }
    vector<int> dp(n + 1, numeric_limits<int>::max());
    dp[0] = numeric_limits<int>::min();
    for (size_t i = 0; i < m; ++i) {
        if (processedData[i] == -1) {
            continue;
        }
        auto replaceableIt = upper_bound(dp.begin(), dp.end(), processedData[i]);
        if (replaceableIt != dp.end()) {
            *replaceableIt = processedData[i];
        }
    }
    vector<int> lcs;
    for (size_t i = 1; i <= n && dp[i] != numeric_limits<int>::max(); ++i) {
        lcs.push_back(A[dp[i]]);
    }
    return {lcs.size(), lcs};
}
