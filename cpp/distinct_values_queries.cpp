#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

template<typename T> struct fenwick_tree {
  private:
    int n;
    std::vector<T> tree;

  public:
    fenwick_tree(int _n) : n(_n), tree(_n, T(0)) {}

    T prefix_sum(int r) {
        T sum = T(0);
        while (r >= 0) {
            sum += tree[r];
            r = (r & (r + 1)) - 1;
        }
        return sum;
    }

    T query(int l, int r) { 
        return prefix_sum(r) - prefix_sum(l - 1); 
    }

    void update(int i, long long delta) { 
        while (i < n) {
            tree[i] += delta;
            i = i | (i + 1);
        }
    }
};


int main(){
    int n, q; 
    std::cin >> n >> q; 
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::vector<std::vector<std::pair<int, int>>> with_endpoint(n);
    for (int i = 0, l, r; i < q; ++i) {
        std::cin >> l >> r;
        with_endpoint[r - 1].emplace_back(l - 1, i);
    }

    fenwick_tree<int> FT(n);
    std::map<int, int> last_occ;
    std::vector<int> answer(q);
    for (int r = 0; r < n; ++r) {
        if (last_occ.count(a[r])) FT.update(last_occ[a[r]], -1);
        FT.update(last_occ[a[r]] = r, +1);
        for (auto [l, i] : with_endpoint[r]) answer[i] = FT.query(l, r);
    }
    for (int ans : answer) std::cout << ans << '\n';
    return 0;
}
