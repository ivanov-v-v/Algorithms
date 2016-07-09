vector<int> z_function(const string &s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i-l], r-i+1);
        }
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i]-1 > r) {
            l = i, r = i+z[i]-1;
        }
    }
    return z;
}

vector<int> prefix_function(const string& s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int p_len = pi[i-1];
        while (p_len && s[p_len] != s[i]) {
            p_len = pi[p_len-1];
        }
        if (s[p_len] == s[i]) p_len++;
        pi[i] = p_len;
    }
    return pi;
}
