void dfs_sz(int u, int p) {
    sz[u] = 1;
	for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
		if (v == p) continue;
		par[v] = u;
		dep[v] = dep[u] + 1;
		dfs_sz(v, u);
		sz[u] += sz[v];
	}
}

void dfs_hld(int u, int p, int top) {
	id[u] = ++timer;
	tp[u] = top;
	int h_child = -1, mx = 0;
	for(int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == p) continue;
		if (mx > sz[v]) {
			mx = sz[v];
			h_child = v;
		}
	}

	if (h_child == -1) return;
	dfs_hld(h_child, u, top);
	for(int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == p || v == h_child) continue;
		dfs_hld(v, u, v);
	}
}

void update_hld(int u, int v, int w) {
	while (tp[u] != tp[v]) {
		if (dep[tp[u]] < dep[tp[v]]) swap(u, v);
		st.upd(id[tp[u]], id[u], w);
		u = par[tp[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	st.upd(id[v], id[u], w);
}

int max_hld(int u, int v) {
	int ret = -(int)1e9;
	while (tp[u] != tp[v]) {
		if (dep[tp[u]] < dep[tp[v]]) swap(u, v);
		ret = max(ret, st.get(id[tp[u]], id[u]);
		u = par[tp[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	ret = max(ret, st.get(id[v], id[u]));
	return ret;
}

