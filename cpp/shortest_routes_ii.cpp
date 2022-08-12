#include <algorithm>
#include <iostream>
#include <vector>
const long long INF = 1e18;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<std::vector<int>> adj_matrix(n, std::vector<int>(n));
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		a--, b--;
		if (!adj_matrix[a][b]) {
			adj_matrix[a][b] = c;
		} else {
			adj_matrix[a][b] = std::min(adj_matrix[a][b], c);
		}
		adj_matrix[b][a] = adj_matrix[a][b];
	}
	std::vector<std::vector<long long>> dist(n, std::vector<long long>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				dist[i][j] = 0;
			} else if (adj_matrix[i][j]) {
				dist[i][j] = adj_matrix[i][j];
			} else {
				dist[i][j] = INF;
			}
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--) {
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		std::cout << (dist[a][b] == INF ? -1 : dist[a][b]) << '\n';
	}

	return 0;
}
