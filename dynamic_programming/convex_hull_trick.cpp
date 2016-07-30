struct line{
    ld A, B, C;
    explicit line(ld a, ld b, ld c) {
        A = a;
        B = b;
        C = c;
    }
};

pair<ld, ld> intersection_point(const line& L1, const line& L2) {
    ld A1 = L1.A, B1 = L1.B, C1 = L1.C;
    ld A2 = L2.A, B2 = L2.B, C2 = L2.C;
    ld det = A2*B1 - A1*B2;
    return {(B2*C1 - B1*C2)/det, {(A1*C2 - A2*C1)/det}};
}

//"Convex Hull Trick" data structure.
//d[i] = min_{j < i} { d[j] + a[i]*b[j] }, b[j+1] < b[j]
//O(N^2) -> O(N)
void add_line(vector<pair<line, pair<ld, ld>>>& S, const line &L) {
    while (S.size() > 1) {
        line L2 = S.back().fst;
        line L1 = S[S.size()-2].fst;
        ld x = intersection_point(L1, L2).fst;
        ld nx = intersection_point(L, L2).fst;
        if (x < nx) break;
        S.pop_back();
    }
    if (S.empty()) {
        S.push_back({L, {-1e100, 0}});
    } else {
        S.push_back({L, intersection_point(L, S.back().fst)});
    }
}

ld optimal_value(vector<pair<line, pair<ld, ld>>>& S, ld x0) {
    int lo = 0, hi = S .size()-1;
    while (lo < hi) {
        int mid = (hi+lo)/2;
        if (S[mid].scd.fst < x0) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    ld A = S[lo].fst.A, k = -S[lo].fst.B/A, b = -S[lo].fst.C/A;
    return k*x0+b;
}
