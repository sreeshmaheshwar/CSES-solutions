#include <iostream>
#include <vector>
#include <numeric>

struct union_find {
  private:
	int cnt, mx_size = 1;
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
		mx_size = std::max(mx_size, sizes[x]);
		cnt--;
		return true;
	}
 
	int count() const { return cnt; }

	int max_size() const { return mx_size; }
};

int main() {
	int n, m; 
	std::cin >> n >> m;
	union_find UF(n);
	for (int i = 0; i < m; ++i) {
		int u, v; 
		std::cin >> u >> v;
		u--, v--;
		UF.unite(u, v);
		std::cout << UF.count() << " " << UF.max_size() << '\n';
	}
	return 0;
}