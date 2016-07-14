ll depth(ll x) {
    ll answ = 1;
    while (x != 1) {
        x /= 2;
        answ++;
    }
    return answ;
}

ll lca_heap(ll u, ll v) {
    ll du = depth(u),
        dv = depth(v);
    while (u != v) {
        if (du < dv) {
            swap(u, v);
            swap(du, dv);
        }
        u /= 2;
        du--;
    }
    return u;
}
