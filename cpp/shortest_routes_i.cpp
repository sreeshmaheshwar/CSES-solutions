#include <iostream>
#include <queue>
#include <utility>
#include <vector>
const long long INF = 1e18;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0, a, b, c; i < m; ++i) {
        std::cin >> a >> b >> c;
        adj[a - 1].emplace_back(b - 1, c);        
    }

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> q;
    std::vector<long long> dist(n, INF);
    std::vector<bool> processed(n, false);

    int start_node = 0;
    dist[start_node] = 0;
    q.emplace(dist[start_node], start_node);

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (processed[u]) continue;
        processed[u] = true;
        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                q.emplace(dist[v], v);
            }
        }
    }
    
    for (int i = 0; i < n; ++i)
        std::cout << dist[i] << " ";
    return 0;
}