int dfs_sz(int u, int p) {
    sz[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        sz[u] += sz[v];
    }
    return sz[u];
}

int get_centroid(int u, int tree_size, int p) {
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p || is_removed[v]) continue;
        if (sz[v] * 2 > tree_size) return get_centroid(v, tree_size, u);
    }
    return u;
}

void solve(int u, int cent, int p) {
    // solve the problem here and use a delete vector to store all the
    // elements that needed to be refreshed after this centroid
    // Create an in_map array which in_map[i] = true when i is in the delete vector
}

void upd(int u, int cent, int p) {
    // update all the information for subtrees of u
    // to solve for next subtree of centroid
}

void build_centroid_decomp(int u) { // u may not be centroid
    int centroid = get_centroid(u, dfs_sz(u), -1);

    for (int i = 0; i < (int)adj[centroid].size(); ++i) {
        int v = adj[centroid][i];
        if (is_removed[v]) continue;
        solve(v, centroid, centroid);
    }

    is_removed[centroid] = true;
    for (int i = 0; i < (int)adj[centroid].size(); ++i) {
        int v = adj[centroid][i];
        if (is_removed[v]) continue;
        build_centroid_decomp(v);
    }
}
