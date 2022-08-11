#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct union_find {

  private:

	int cnt, mx_size = 1;
	std::vector<int> sizes, link;
 
  public:

	union_find() {}
 
	union_find(int n) : cnt(n), sizes(n, 1), link(n, 0) { std::iota(link.begin(), link.end(), 0); }
 
	int find(int x) { return ( x == link[x] ? x : link[x] = find(link[x])); }
 
	bool same(int x, int y) { return find(x) == find(y); }
 
	bool unite(int x, int y) {
		x = find(x); 
		y = find(y);
		if (x == y) return false;
		if (sizes[x] < sizes[y]) std::swap(x, y);
		sizes[x] += sizes[y];
		link[y] = x;
		cnt--;
		return true;
	}
 
	int size(int x) { return sizes[find(x)]; }
 
	int count() const { return cnt; }	
};

struct Edge {
	int u, v, weight;
};
 
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 
	int n, m; 
	std::cin >> n >> m;
	std::vector<Edge> edges(m);
	for (Edge &edge : edges) {
		std::cin >> edge.u >> edge.v >> edge.weight;
		edge.u--, edge.v--;
	}
 
	std::sort(edges.begin(), edges.end(), [](const Edge& lhs, const Edge& rhs) {
		return lhs.weight < rhs.weight;
	});
 
	long long ans = 0;
	union_find UF(n);
	for (Edge e : edges) {
		ans += UF.unite(e.u, e.v) * e.weight;
	}
	std::cout << (UF.count() > 1 ? "IMPOSSIBLE" : std::to_string(ans)) << '\n';
 
	return 0;
}