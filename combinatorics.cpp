/** C(k, n) = C(k, n - 1) + C(k - 1, n - 1) **/
/** C(k, n) = n! / (k! * (n - k)!)          **/

// O(n^2) prepare, O(1) query
for (int i = 0; i < MAX; ++i) comb[0][i] = 1;

for (int i = 1; i < MAX; ++i) for (int j = 1; j < MAX; ++j) {
    if (i > j) comb[i][j] = 0;
    if (i == j) comb[i][j] = 1;
    if (i < j) {
        comb[i][j] = comb[i][j - 1] + comb[i - 1][j - 1];
        if (comb[i][j] >= MOD) comb[i][j] -= MOD;
    }
}

// O(n) prepare, O(1) query, modulo inversion
// a / b -> a * b^(MOD - 2) % MOD
frac[0] = 1;
for (int i = 1; i < MAX; ++i) frac[i] = 1LL * frac[i - 1] * i % MOD;
finv[MAX - 1] = POW(frac[MAX - 1], MOD - 2);
for (int i = MAX - 2; i >= 0; --i) finv[i] = 1LL * finv[i + 1] * (i + 1) % MOD;
int comb(int k, int n) {
    return k > n ? 0 : 1LL * frac[n] * finv[k] % MOD * finv[n - k] % MOD;
}

// O(k) prepare, O(k) query, modulo > k, k <= 10^6, n <= 10^18
int comb(int k, long long n) {
    int res = finv[k];
    for (int i = 0; i < k; ++i) res = 1LL * (n - i) % MOD * res % MOD;
    return res;
}
