#include <iostream>
#include <vector>
#include <numeric>

struct union_find {
  private:
    int num_components;
	int max_size;
    std::vector<int> sizes;
	std::vector<int> link;
 
  public:
    union_find(int n) : num_components(n), max_size(1), sizes(n, 1), link(n, 0) {
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
		max_size = std::max(max_size, sizes[x]);
        return true;
    }

    int count() {
        return num_components;
    }

	int largest() {
		return max_size;
	}
};

int main() {
	int n, m; 
	std::cin >> n >> m;
	union_find UF(n);
	for (int i = 0, u, v; i < m; ++i) {
		std::cin >> u >> v;
		UF.unite(u - 1, v - 1);
		std::cout << UF.count() << " " << UF.largest() << '\n';
	}
	return 0;
}