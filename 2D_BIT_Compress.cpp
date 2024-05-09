// Normal update point (x, y)
void update(int x, int y, int val) {
    for (; x <= n; x += x & -x)
        for (int v = y; v <= m; v += v & -v)
            node[x][v] += val;
}
// Normal get sum of rectangle (1, 1) -> (x, y)
int get2D(int x, int y) {
    int ret = 0;
    for (; x > 0; x &= x - 1)
        for (int v = y; v > 0; v &= v - 1)
            ret += node[x][v];
    return ret;
}
/** Compress (Only use when have known all queries) **/
// fake update (x, y) -> only q * log(n) * log(m) nodes
void fakeUpdate(int x, int y) {
    for (; x <= n; x += x & -x)
        node[x].pb(y);
}
// fake get (x, y)
void fakeGet(int x, int y) {
    for (; x > 0; x &= x - 1)
        node[x].pb(y);
}
void update(int x, int yy, int val) {
    for (; x <= n; x += x & -x)
        for (int y = lower_bound(node[x].begin(), node[x].end(), yy) - node[x].begin() + 1;
                 y <= node[x].size(); y += y & -y)
            BIT[x][y - 1] += val;
}
int get2D(int x, int yy) {
    int ret = 0;
    for (; x > 0; x &= x - 1)
        for (int y = lower_bound(node[x].begin(), node[x].end(), yy) - node[x].begin() + 1;
                 y > 0; y &= y - 1)
            ret += BIT[x][y - 1];
    return ret;
}
/** Besides sum can also use for max query from (1, 1) to (x, y) **/
