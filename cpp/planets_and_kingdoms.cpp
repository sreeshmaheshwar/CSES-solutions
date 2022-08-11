#include <iostream>
#include <vector>
#include <functional>
 
int main() {
	std::ios::sync_with_stdio(0); 
	std::cin.tie(0);

	int n, m; 
	std::cin >> n >> m;
	std::vector<std::vector<int>> adj(n), transpose_adj(n);
	for (int i = 0; i < m; ++i) {
		int u, v; 
		std::cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		transpose_adj[v].push_back(u);
	}
 
	std::vector<bool> visited(n, false);
	std::vector<int> order;
	std::function<void(int)> dfs = [&](int u) {
		visited[u] = 1;
		for (int v : adj[u]) {
			if (!visited[v]) {
				dfs(v);
			}
		}
		order.push_back(u);
	};
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
 
	int num_components = 0;
	std::vector<int> kingdom(n, -1);
	std::function<void(int)> dfs_transpose = [&](int u) {
		kingdom[u] = num_components;
		for (int v : transpose_adj[u]) {
			if (kingdom[v] == -1) {
				dfs_transpose(v);
			}
		}
	};
	while (!order.empty()) {
		int u = order.back();
		order.pop_back();
		if (kingdom[u] == -1) {
			num_components++;
			dfs_transpose(u);
		}
	}
	
	std::cout << num_components << '\n';
	for (int i = 0; i < n; ++i) {
		std::cout << kingdom[i] << " ";
	}
	
	return 0;
}
