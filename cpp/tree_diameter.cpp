#include <algorithm>
#include <iostream>
#include <functional>
#include <utility>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> adj(n + 1);
	while (--n) {
		int a, b;
		std::cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	std::pair<int, int> farthest = {0, 1};
	std::function<void(int, int, int)> dfs = [&](int node, int par, int depth) {
		farthest = std::max(farthest, {depth, node});
		for (int child : adj[node])
			if (child != par)
				dfs(child, node, depth + 1);
	};
	for (int iter = 0; iter < 2; ++iter)
		dfs(farthest.second, 0, 0);
	std::cout << farthest.first << '\n';
	return 0;
}
