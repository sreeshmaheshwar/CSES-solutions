#include <functional>
#include <iostream>
#include <vector>
const int MOD = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		adj[a - 1].push_back(b - 1);
	}
	std::vector<int> routes(n, -1);
	std::function<void(int)> dfs = [&](int u) {
		if (u == n - 1) {
			routes[u] = 1;
		} else {
			routes[u] = 0;
			for (int v : adj[u]) {
				if (routes[v] == -1) dfs(v);
				routes[u] = ((long long) routes[u] + routes[v]) % MOD;
			}
		}
	};
	dfs(0);
	std::cout << routes[0] << std::endl;

	return 0;
}
