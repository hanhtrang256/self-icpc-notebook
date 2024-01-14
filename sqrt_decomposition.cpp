int BLOCK = (int)sqrt(n);
long long sum[N];

void precalc() {
    for (int i = 0; i < n; ++i)
        sum[i / BLOCK] += a[i];
}

// set a[x] to v
void upd(int x, int v) {
    sum[x / BLOCK] -= a[x];
    a[x] = v;
    sum[x / BLOCK] += a[x];
}

/** sum of [0, r)  O(sqrt(n)) **/
/** l, r start from 1 in this function **/
long long query(int r) {
    long long ret = 0;
    for (int i = 0; i < r / BLOCK; ++i) ret += sum[i];
    for (int i = (r / BLOCK) * BLOCK; i < r; ++i) ret += a[i];
    return ret;
}

/** sum of [l, r) O(sqrt(n)) **/
/** l, r start from 1 in this function **/
long long query(int l, int r) {
    return query(r) - query(l - 1);
}
