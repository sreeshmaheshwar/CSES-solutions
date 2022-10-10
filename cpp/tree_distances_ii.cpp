#include <iostream>
#include <functional>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0, a, b; i < n - 1; ++i) {
        std::cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::vector<int> subtree_size(n, 1);
    std::vector<int> parent(n, -1);
    std::vector<int> order;
    std::vector<int64_t> answer(n);

    std::function<void(int, int)> dfs = [&](int node, int depth) {
        order.push_back(node);
        answer[0] += depth;
        for (int child : adj[node]) {
            if (child != parent[node]) {
                parent[child] = node;
                dfs(child, depth + 1);
                subtree_size[node] += subtree_size[child];
            }
        }
    };
    dfs(0, 0);

    for (int i = 1; i < n; ++i)
        answer[order[i]] = answer[parent[order[i]]] + n - 2 * subtree_size[order[i]];
    for (int node = 0; node < n; ++node)
        std::cout << answer[node] << " ";
    return 0;
}