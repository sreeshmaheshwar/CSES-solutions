#include <algorithm>
#include <iostream>
#include <vector>
const long long INF = 1e18;

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<long long>> dist(n + 1, std::vector<long long>(n + 1, INF));
    for (int i = 0, a, b, c; i < m; ++i) {
        std::cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = std::min<long long>(dist[a][b], c);
    }

    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
	
	for (int i = 0, a, b; i < q; ++i) {
		std::cin >> a >> b;
		std::cout << (dist[a][b] == INF ? -1 : dist[a][b]) << '\n';
	}
    return 0;
}
