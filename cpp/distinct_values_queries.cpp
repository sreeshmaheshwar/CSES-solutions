#include <bits/stdc++.h>
using namespace std;
 
struct fenwick_tree {
 
    vector<long long> bit;
    int n;
 
    fenwick_tree(int _n) : n(_n) {
        bit.assign(n, 0);
    }
 
    long long sum(int r) {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += bit[r];
        return res;
    }
 
    long long qry(int l, int r) { 
        return sum(r) - sum(l - 1); 
    }
 
    void upd_by(int idx, long long delta) { 
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
 
struct query {
	int l, r, index; 
};
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q; 
	cin >> n >> q; 
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<query> queries;
	for (int i = 0; i < q; ++i) {
		int l, r; 
		cin >> l >> r; 
		l--, r--;
		queries.push_back(query{l, r, i});
	}
 
	sort(queries.begin(), queries.end(), [](const query& lhs, const query& rhs) {
		return lhs.r < rhs.r;
	});
 
	fenwick_tree ft(n);
	map<int, int> last_occurance;
	vector<int> answer(q);
 
	for (int i = 0, j = 0; i < n && j < q; ++i) {
		if (last_occurance.count(a[i])) {
			ft.upd_by(last_occurance[a[i]], -1);
		}
		last_occurance[a[i]] = i; 
		ft.upd_by(i, 1);
		// answer all queries with this endpoint
		while (j < q && queries[j].r == i) {
			answer[queries[j].index] = ft.qry(queries[j].l, queries[j].r);
			j++;
		}
	}
	for (int ans : answer) cout << ans << '\n';
 
	return 0;
}
