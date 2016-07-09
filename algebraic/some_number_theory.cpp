ll inverse(ll a, ll m) {
    ll x, y;
    ll g = gcd_ex(a, m, x, y);
    if (g != 1) {
        cout << "Not invertible\n";
        return -1;
    }
    return mod(x, m);
}

pll solve(ll a, ll b, ll c) {
    ll x, y;
    ll g = gcd_ex(a, b, x, y);
    assert(c % g == 0);
    return {x * (c/g), y * (c/g)};
}

ll chinese(vector<pll> system) {
    ll M = accumulate(all(system), 1LL, [](ll prod, pll entry) { return prod*entry.scd; });
    int n = system.size();
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll Mi = M/system[i].scd;
        res += Mi*inverse(Mi, system[i].scd)*system[i].fst;
    }
    res %= M;
    for (int i = 0; i < n; i++) {
        cout << res%system[i].scd << " " << system[i].scd << "\n";
    }
    return res;
}

ll legendre(ll q, ll p) {
    q %= p;
    ll res = 1;
    while (q != 0) {
        while (q % 2 == 0) {
            q /= 2;
            if (p % 8 == 3 || p % 8 == 5) {
                res *= (-1);
            }
        }
        swap(q, p);
        q %= p;
        if (p % 4 == 3 && q % 4 == 3) {
            res *= (-1);
        }
    }
    return p == 1 ? res : 0;
}
