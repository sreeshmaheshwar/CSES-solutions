#include <bits/stdc++.h>
using namespace std;
 
struct union_find {
 
  private:
 
	int cnt;
	vector<int> sizes, link;
 
  public:
 
	union_find() {}
 
	union_find(int n) : cnt(n), sizes(n, 1), link(n, 0) { iota(link.begin(), link.end(), 0); }
 
	int find(int x) { return ( x == link[x] ? x : link[x] = find(link[x])); }
 
	bool same(int x, int y) { return find(x) == find(y); }
 
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (sizes[x] < sizes[y])
			swap(x, y);
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
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, m; 
	cin >> n >> m;
	vector<Edge> edges(m);
	for (Edge &edge : edges) {
		cin >> edge.u >> edge.v >> edge.weight;
		edge.u--, edge.v--;
	}
 
	sort(edges.begin(), edges.end(), [](const Edge& lhs, const Edge& rhs) {
		return lhs.weight < rhs.weight;
	});
 
	long long ans = 0;
	union_find UF(n);
	for (Edge e : edges) {
		ans += UF.unite(e.u, e.v) * e.weight;
	}
	cout << (UF.count() > 1 ? "IMPOSSIBLE" : to_string(ans)) << '\n';
 
	return 0;
}