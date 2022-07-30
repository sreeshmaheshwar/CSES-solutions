#include <bits/stdc++.h>
using namespace std;

struct union_find {

  private:

	int cnt, mx_size = 1;
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
		mx_size = max(mx_size, sizes[x]);
		link[y] = x;
		cnt--;
		return true;
	}
 
	int size(int x) { return sizes[find(x)]; }
 
	int count() const { return cnt; }

	int max_size() { return mx_size; }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, m; 
	cin >> n >> m;
	union_find UF(n);
	for (int i = 0; i < m; ++i) {
		int u, v; 
		cin >> u >> v;
		u--, v--;
		UF.unite(u, v);
		cout << UF.count() << ' ' << UF.max_size() << '\n';
	}
 
	return 0;
}