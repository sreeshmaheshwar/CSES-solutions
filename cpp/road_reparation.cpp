#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct union_find {
  private:
    int num_components;
    std::vector<int> sizes;
    std::vector<int> link;
 
  public:
    union_find(int n) : num_components(n), sizes(n, 1), link(n, 0) {
        std::iota(link.begin(), link.end(), 0);
    }
 
    int find(int x) {
        return x == link[x] ? x : link[x] = find(link[x]);
    }
 
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        link[y] = x;
        sizes[x] += sizes[y];
        num_components--;
        return true;
    }

    int count() {
        return num_components;
    }   
};

struct edge {
    int u, v, weight;

    bool operator<(const edge &e) const {
        return weight < e.weight;
    }
};

int main() {
    int n, m; 
    std::cin >> n >> m;
    std::vector<edge> edges(m);
    for (auto &[u, v, w] : edges)
        std::cin >> u >> v >> w;

    std::sort(edges.begin(), edges.end());
    union_find UF(n);
    long long ans = 0;
    for (auto &[u, v, w] : edges)
        ans += UF.unite(u - 1, v - 1) * w;

    std::cout << (UF.count() > 1 ? "IMPOSSIBLE" : std::to_string(ans));
    return 0;
}