// returns number of elements > k in range [l...r]
struct segmenttree
{
	int n;
	vector < vector < int > > arr;
	segmenttree(int _n, int a[]) {
		n = _n;
		arr.assign(4 * n + 6, {});
		build(1, 1, n, a);
	}
	void build(int i, int l, int r, int a[]) {
		if (l == r) {
			arr[i].push_back(a[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(i << 1, l, mid, a);
		build(i << 1 | 1, mid + 1, r, a);
		int it = 0, jt = 0;
		while (it < (int)arr[i << 1].size() && jt < (int)arr[i << 1 | 1].size()) {
			if (arr[i << 1][it] <= arr[i << 1 | 1][jt]) {
				arr[i].push_back(arr[i << 1][it]);
				++it;
			}
			else {
				arr[i].push_back(arr[i << 1 | 1][jt]);
				++jt;
			}
		}
		while (it < (int)arr[i << 1].size()) { arr[i].push_back(arr[i << 1][it]); ++it; }
		while (jt < (int)arr[i << 1 | 1].size()) { arr[i].push_back(arr[i << 1 | 1][jt]); ++jt; }
	}
    // > k
	int get(int i, int l, int r, int u, int v, int k) {
		if (l > r || u > v || l > v || r < u) return 0;
		if (l >= u && r <= v)
			return (int)arr[i].size() - (upper_bound(arr[i].begin(), arr[i].end(), k) - arr[i].begin());
		int mid = (l + r) >> 1;
		return get(i << 1, l, mid, u, v, k) + get(i << 1 | 1, mid + 1, r, u, v, k);
	}
	int get(int u, int v, int k) { return get(1, 1, n, u, v, k); }
};
