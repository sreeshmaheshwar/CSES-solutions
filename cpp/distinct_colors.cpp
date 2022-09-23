#include <iostream>
#include <functional>
#include <set>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> C(N);
    for (int& colour : C) 
        std::cin >> colour;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    std::vector<std::set<int>> subtree_colours(N);
    auto merge_subtrees = [&](std::set<int>& from, std::set<int>& to) -> void {
        if (from.size() > to.size()) swap(from, to);
        to.insert(from.begin(), from.end());
    };

    std::vector<int> answer(N);
    std::function<void(int, int)> dfs = [&](int node, int parent) -> void {
        subtree_colours[node].insert(C[node]);
        for (const int& child : adj[node]) {
            if (child != parent) {
                dfs(child, node);
                merge_subtrees(subtree_colours[child], subtree_colours[node]);
            }
        }
        answer[node] = subtree_colours[node].size();
    };
    dfs(0, -1);

    for (int i = 0; i < N; ++i) 
        std::cout << answer[i] << " ";
    return 0;
}