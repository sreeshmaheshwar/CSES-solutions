#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

struct fenwick_tree {

    std::vector<long long> data;
    int n;
 
    fenwick_tree(int _n) : n(_n) {
        data.assign(n, 0);
    }
 
    long long sum(int r) {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += data[r];
        return res;
    }
 
    long long query(int l, int r) { 
        return sum(r) - sum(l - 1); 
    }
 
    void update_by(int index, long long delta) { 
        for (; index < n; index = index | (index + 1))
            data[index] += delta;
    }
};

struct query {

	int l, r, index; 
};
 
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, q; 
	std::cin >> n >> q; 
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::vector<query> queries;
	for (int i = 0; i < q; ++i) {
		int l, r; 
		std::cin >> l >> r; 
		l--, r--;
		queries.push_back(query{l, r, i});
	}
 
	std::sort(queries.begin(), queries.end(), [](const query& lhs, const query& rhs) {
		return lhs.r < rhs.r;
	});
 
	fenwick_tree ft(n);
	std::map<int, int> last_occurance;
	std::vector<int> answer(q);
	for (int i = 0, j = 0; i < n && j < q; ++i) {
		if (last_occurance.count(a[i])) {
			ft.update_by(last_occurance[a[i]], -1);
		}
		last_occurance[a[i]] = i; 
		ft.update_by(i, 1);
		// answer all queries with this endpoint
		while (j < q && queries[j].r == i) {
			answer[queries[j].index] = ft.query(queries[j].l, queries[j].r);
			j++;
		}
	}
	for (int ans : answer) std::cout << ans << '\n';
 
	return 0;
}
