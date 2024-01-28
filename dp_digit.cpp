// count number of x in [a,b] that does not contain 13
long long DP(int pos, int pre, int f) {
    if (pos == (int)num.size()) return 1;
    long long &res = dp[pos][pre][f];
    if (res != -1) return res;
    res = 0;
    int lim = (f == 1 ? 9 : num[pos]);
    for (int i = 0; i <= lim; ++i) {
        if (i == 3 && pre == 1) continue;
        int nf = f;
        if (f == 0 && i < lim) nf = 1;
        res += DP(pos + 1, i, nf);
    }
    return res;
}
long long solve(long long x) {
    if (x < 0) return 0;
    num.clear();
    while (x > 0) {
        num.pb(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof dp);
    return DP(0, 0, 0);
}
