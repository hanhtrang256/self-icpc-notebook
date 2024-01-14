const int NMOD = 4;
const int MOD[] = {(int)1e9 + 7, (int)1e9 + 2277, (int)1e9 + 5277, (int)998244353};
const int base = 256;

long long pw[N][NMOD], hsh[N][NMOD];

long long get(int l, int r) {
    return (hsh[r] - hsh[l - 1] * pw[r - l + 1] + 1LL * MOD * MOD) % MOD;
}

int main() {
    for (int i = 0; i < NMOD; ++i) pw[0][i] = 1;
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < NMOD; ++j)
            pw[i][j] = 1LL * pw[i - 1][j] * base % MOD[j];

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < NMOD; ++j)
            hsh[i][j] = (1LL * hsh[i - 1][j] * base + (s[i] - 'a' + 1)) % MOD[j];
    return 0;
}
