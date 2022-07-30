#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	long long cur = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		cur += a[i].first;
		ans += a[i].second - cur;
	}
	cout << ans << '\n';
 
	return 0;
}
