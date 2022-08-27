#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct union_find {
  private:
	int cnt;
	std::vector<int> sizes, link;
 
  public:
	union_find(int n) : cnt(n), sizes(n, 1), link(n, 0) { std::iota(link.begin(), link.end(), 0); }
 
	int find(int x) { return x == link[x] ? x : link[x] = find(link[x]); }
 
	bool unite(int x, int y) {
		x = find(x); 
		y = find(y);
		if (x == y) return false;
		link[y] = x;
		sizes[x] += sizes[y];
		cnt--;
		return true;
	}

	int count() const { return cnt; }	
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
	for (edge &e : edges) {
		std::cin >> e.u >> e.v >> e.weight;
		e.u--, e.v--;
	}
	std::sort(edges.begin(), edges.end());
	long long ans = 0;
	union_find UF(n);
	for (const edge &e : edges) {
		ans += UF.unite(e.u, e.v) * e.weight;
	}
	std::cout << (UF.count() > 1 ? "IMPOSSIBLE" : std::to_string(ans)) << '\n';
	return 0;
}