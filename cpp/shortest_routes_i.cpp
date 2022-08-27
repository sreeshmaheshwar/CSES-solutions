#include <iostream>
#include <queue>
#include <utility>
#include <vector>
const long long INF = 1e18;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);        
    }

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> q;
    std::vector<long long> dist(n, INF);
    std::vector<bool> fringe(n, false);

    int start_node = 0;
    dist[start_node] = 0;
    q.emplace(dist[start_node], start_node);

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (fringe[u]) continue;
        fringe[u] = true;
        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                q.emplace(dist[v], v);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << dist[i] << " ";
    }
    std::cout << '\n';
    return 0;
}