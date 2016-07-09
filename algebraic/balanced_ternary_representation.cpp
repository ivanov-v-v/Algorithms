vector<int> ternary_balanced_representation(ll n){
    vector<int> representation;
    for (ll pow = 3; n; pow *= 3) {
        representation.pb(n % 3);
        n /= 3;
    }
    int carry = 0;
    for (int i = 0; i < representation.size(); i++) {
        representation[i] += carry;
        carry = 0;
        if (representation[i] == 2) {
            representation[i] = -1;
            carry++;
        } else if (representation[i] >= 3) {
            carry += representation[i]/3;
            representation[i] %= 3;
        }
    }
    if (carry) representation.pb(carry);
    return representation;
}
