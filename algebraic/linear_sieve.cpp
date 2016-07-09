class sieve{
private:
    ll N;
    vector<ll> lp;
    vector<ll> primes;
public:
    sieve(ll range) {
        N = range;
        lp.resize(N+1);
        for (int i = 2; i <= N; i++) {
            if (!lp[i]) {
                lp[i] = i;
                primes.pb(lp[i]);
            }
            for (int j = 0; j < primes.size() && i*primes[j] <= N && primes[j] <= lp[i]; j++) {
                lp[i*primes[j]] = primes[j];
            }
        }
    }
    bool is_prime(ll n) {
        assert(n <= N);
        return lp[n] == n;
    }
    vector<pll> factorize(ll n) {
        assert(1 <= n && n <= N);
        vector<pll> factorization;
        while (lp[n]) {
            ll d = lp[n];
            ll a = 0;
            while (lp[n] == d) {
                n /= d;
                a++;
            }
            factorization.emplace_back(d, a);
        }
        if (n != 1) {
            factorization.emplace_back(n, 1);
        }
        return factorization;
    }
};
