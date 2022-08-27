#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template<typename T> struct fenwick_tree {
    std::vector<T> data;
    int n;
 
    fenwick_tree(int _n, T initial) : n(_n) {
        data.assign(n, initial);
    }
 
    T prefix_sum(int r) {
        T res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += data[r];
        return res;
    }
 
    T query(int l, int r) { 
        return prefix_sum(r) - prefix_sum(l - 1); 
    }
 
    void update(int index, long long delta) { 
        for (; index < n; index = index | (index + 1))
            data[index] += delta;
    }
};

struct query {
	int l, r, index;

	bool operator<(const query &q) const {
		return r < q.r;
	}
};
 
int main(){
	int n, q; 
	std::cin >> n >> q; 
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::vector<query> queries;
	for (int i = 0; i < q; ++i) {
		int l, r; 
		std::cin >> l >> r; 
		l--, r--;
		queries.push_back(query{l, r, i});
	}
	std::sort(queries.begin(), queries.end());
	fenwick_tree<int> ft(n, 0);
	std::map<int, int> last_occurance;
	std::vector<int> answer(q);
	for (int i = 0, j = 0; i < n && j < q; ++i) {
		if (last_occurance.count(a[i])) {
			ft.update(last_occurance[a[i]], -1);
		}
		last_occurance[a[i]] = i; 
		ft.update(i, 1);
		// answer all queries with this endpoint
		while (j < q && queries[j].r == i) {
			answer[queries[j].index] = ft.query(queries[j].l, queries[j].r);
			j++;
		}
	}
	for (int ans : answer)
		std::cout << ans << '\n';
	return 0;
}
