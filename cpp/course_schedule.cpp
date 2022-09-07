#include <iostream>
#include <vector>
#include <utility>

struct directed_graph {
    std::vector<std::vector<int>> adj;
    std::vector<int> in_degree;
    int num_nodes;

    directed_graph(int n) : num_nodes(n) {
        adj.assign(num_nodes, {});
        in_degree.assign(num_nodes, 0);
    }

    void add_edge(int i, int j) {
        adj[i].push_back(j);
        in_degree[j]++;
    }

    std::pair<bool, std::vector<int>> topo_sort() {
        std::vector<int> order;
        for (int i = 0; i < num_nodes; ++i) {
            if (!in_degree[i]) {
                order.push_back(i);
            }
        }
        for (int i = 0; i < (int) order.size(); ++i) {
            for (int j : adj[order[i]]) {
                in_degree[j]--;
                if (!in_degree[j]) {
                    order.push_back(j);
                }
            }
        }
        return {(int) order.size() == num_nodes, order};
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    directed_graph graph(n);
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        graph.add_edge(a - 1, b - 1);
    }
    auto [is_possible, topo_sort] = graph.topo_sort();
    if (is_possible) {
        for (const int& node : topo_sort) {
            std::cout << node + 1 << " ";
        }
    } else {
        std::cout << "IMPOSSIBLE";
    }
    return 0;
}

