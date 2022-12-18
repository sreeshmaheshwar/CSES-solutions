#include <algorithm>
#include <iostream>
#include <vector>

const long long INF = (long long) 1e18;

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, INF));
    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (int i = 0, a, b, w; i < m; ++i) {
        std::cin >> a >> b >> w, a--, b--;
        dist[a][b] = dist[b][a] = std::min<long long>(dist[a][b], w);
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0, a, b; i < q; ++i) {
        std::cin >> a >> b, a--, b--;
        std::cout << (dist[a][b] == INF ? -1 : dist[a][b]) << std::endl;
    }
}