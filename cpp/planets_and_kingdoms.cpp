#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n), transpose_adj(n);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		transpose_adj[v].push_back(u);
	}
 
	vector<bool> vis(n, false);
	vector<int> order;
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (int v : adj[u]) {
			if (!vis[v]) dfs(v);
		}
		order.push_back(u);
	};
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs(i);
	}
 
	int comp_cnt = 0;
	vector<int> kingdom(n, -1);
	function<void(int)> dfs_transpose = [&](int u) {
		kingdom[u] = comp_cnt;
		for (int v : transpose_adj[u]) {
			if (kingdom[v] == -1) dfs_transpose(v);
		}
	};
	while (!order.empty()) {
		int u = order.back(); order.pop_back();
		if (kingdom[u] == -1) {
			comp_cnt++;
			dfs_transpose(u);
		}
	}
	cout << comp_cnt << endl;
	for (int i = 0; i < n; ++i) {
		assert(kingdom[i]);
		cout << kingdom[i] << " ";
	}
	cout << endl;
	
	return 0;
}