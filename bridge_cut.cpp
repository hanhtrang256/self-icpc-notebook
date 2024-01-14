struct Edge {
	int u, v;
	bool used; // visited node
	bool isBridge;

	Edge(int _u = 0, int _v = 0) {
		u = _u; v = _v;
		used = false;
		isBridge = false;
	}
};

#define MAX   250250
int numNode, numEdge, cnt;
Edge edges[MAX];
vector<int> adj[MAX]; // save index of edge, not nodes
bool isCut[MAX];
int numChild[MAX]; // num child of u in dfs tree

cin >> numNode >> numEdge;
for (int i = 1; i <= numEdge; i++) {
	int u, v; cin >> u >> v;
	edges[i] = Edge(u, v);
	adj[u].push_back(i);
	adj[v].push_back(i);
}

void dfs(int u) {
	low[u] = numNode + 1;
	num[u] = ++cnt;

	for (int index : adj[u]) if (!edges[index].used) {
		edges[index].used = true;
		int v = edges[index].u ^ edges[index].v ^ u;
		if (num[v] == 0) {
			numChild[u]++;
			dfs(v);
			minimize(low[u], low[v]);
			edges[index].isBridge = low[v] > num[u];
			if (low[v] >= num[u]) isCut[u] = true;

		} else minimize(low[u], num[v]);
	}
}

for (int i = 1; i <= numNode; i++) if (num[i] == 0) {
	dfs(i);
	// i = root of dfs tree and numchild < 2 => iscut = false
	if (numChild[i] < 2) isCut[i] = false;
}

