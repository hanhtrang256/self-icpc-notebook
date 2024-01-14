void tarjan(int u) {
    num[u] = low[u] = ++timer;
    st.push(u);
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (num[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        ++scc;
        int v;
        do {
            v = st.top();
            st.pop();
            num[v] = low[v] = inf;
        } while (v != u);
    }
}
