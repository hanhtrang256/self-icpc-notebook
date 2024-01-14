void dfs_size(int u, int p) {
    sz[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
    }
}

void dfs(int u, int p, bool keep) { // boolean keep to know we're working on big or small child
    int maxx = -1, bigchild = -1;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        if (maxx < sz[v]) {
            maxx = sz[v];
            bigchild = v;
        }
    }

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p || v == bigchild) continue;
        dfs(v, u, 0);
    }

    if (bigchild != -1) {
        dfs(bigchild, u, 1);
        swap(vec[u], vec[bigchild]);
    }

    vec[u].push_back(u);
    ++cnt[color[u]];

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p || v == bigchild) continue;
        for (int j = 0; j < (int)vec[v].size(); ++j) {
            vec[u].push_back(vec[v][j]);
            ++cnt[color[vec[v][j]]];
        }
    }

    // answer for u is cnt[color[u]]
    // now we erase
    if (keep == 0) {
        for (int i = 0; i < (int)vec[u].size(); ++i)
            --cnt[color[vec[i]]];
    }
}
