#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, k; cin >> n >> k;
	vector<int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	auto check = [&](long long x) -> bool {
		int subarray_cnt = 0;
		long long subarray_sum = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > x) return false;
			subarray_sum += a[i];
			if (subarray_sum > x) {
				subarray_cnt++;
				subarray_sum = a[i];
			}
		}
		if (subarray_sum) subarray_cnt++;
		return subarray_cnt <= k;
	};
 
	long long lo = 0, hi = sum, ans = -1;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (check(mid)) {
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ans << '\n';
 
	return 0;
}
