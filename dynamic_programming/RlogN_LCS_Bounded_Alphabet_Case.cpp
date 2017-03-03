#include <iostream>
#include <algorithm>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <map>

using std::pair;
using std::vector;

pair<int, vector<int>> vanillaLCS(const vector<int>& v1, const vector<int>& v2) {
    if (v1.empty() || v2.empty()) {
        return {0, vector<int>()};
    }
    int n = v1.size(), m = v2.size();
    vector<vector<int>> dp(n, vector<int>(m));
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m));
    dp[0][0] = v1[0] == v2[0];
    for (size_t i = 1; i < n; ++i) {
        dp[i][0] = std::max(dp[i - 1][0], int(v1[i] == v2[0]));
        prev[i][0] = {i - 1, 0};
    }
    for (size_t j = 1; j < m; ++j) {
        dp[0][j] = std::max(dp[0][j - 1], int(v1[0] == v2[j]));
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
        if (prev[i][j] == std::make_pair(i - 1, j - 1)) {
            common.push_back(v1[i]);
            --i, --j;
        } else if (prev[i][j] == std::make_pair(i - 1, j)) {
            --i;
        } else  {
            --j;
        }
    }
    if (v1[i] == v2[j]) {
        common.push_back(v1[i]);
    }
    std::reverse(common.begin(), common.end());
    return {dp[n - 1][m - 1], common};
}

// R = sum of occurences of elements from one string in another, R <= N * M
// for random data, the classical algorithm shows better performance due to
// the overhead of data structures used in input-sensitive algorithm
pair<int, vector<int>> RLogNLCS(const vector<int>& v1, const vector<int>& v2) {
    const vector<int>& A = v1.size() < v2.size() ? v2 : v1;
    const vector<int>& B = v1.size() < v2.size() ? v1 : v2;

    int n = v1.size(), m = v2.size();
    std::map<int, std::list<int>> positions;
    for (size_t i = 0; i < m; ++i) {
        positions[B[i]].push_front(i);
    }
    // find posiions of each occurence of elements from A in B
    // sort them in descending order, and replace each element
    // with elements from its list
    vector<int> processedData;
    for (size_t i = 0; i < n; ++i) {
        if (positions[A[i]].empty()) {
            continue;
        }
        auto id = positions[A[i]].begin();
        while (id != positions[A[i]].end()) {
            processedData.push_back(*id);
            ++id;
        }
    }
    // observe that LCS is now reduced to LIS, which can be solved in O(r log n)
    // as what matters is the relative ordering of elements
    // of one array in another, that's why it's enough
    // to subsitute elements with their indices
    // the lists of them must be sorted, because otherwise
    // it will be impossible to include all the consequtive
    // occurences of the same element in the data, if necessary
    int r = processedData.size();
    vector<int> dp(n + 1, std::numeric_limits<int>::max());
    dp[0] = std::numeric_limits<int>::min();
    for (size_t i = 0; i < r; ++i) {
        auto replaceableIt = std::upper_bound(dp.begin(), dp.end(), processedData[i]);
        if (replaceableIt != dp.end()) {
            *replaceableIt = processedData[i];
        }
    }
    vector<int> lcs;
    for (size_t i = 1; i <= n && dp[i] != std::numeric_limits<int>::max(); ++i) {
        lcs.push_back(B[dp[i]]);
    }
    return {lcs.size(), lcs};
}

template<class T> std::ostream& operator <<(std::ostream& os, const vector<T>& Col) {
    for(auto &el : Col) {
        os << el << " ";
    }
    return os;
}

int main() {
    srand(time(0));
    int n, m;
    std::cin >> n >> m;
    char mode = 'y';
    while (mode == 'y') {
        vector<int> v1, v2;
        while (v1.size() != n) {
            v1.push_back(rand() % 100);
        }
        while (v2.size() != m) {
            v2.push_back(rand() % 100);
        }
        auto answ1 = vanillaLCS(v1, v2);
        auto answ2 = RLogNLCS(v1, v2);
        std::cout << answ1.first <<  " " << answ2.first << ": ";
        if (answ1.first != answ2.first) {
            std::cout << answ1.second << "\n"
                      << answ2.second << "\n"
                      << v1 << "\n"
                      << v2 << "\n";
        } std::cout << "\n";
        std::cin >> mode;
    }
    return 0;
}
