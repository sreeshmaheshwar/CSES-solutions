#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int& element : a) cin >> element;
	map<int, pair<int, int>> mp;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int need = x - a[i] - a[j];
			if (mp.count(need)) {
				cout << i+1 << " " << j+1 << " " << mp[need].first+1 << " " << mp[need].second+1;
				return 0;
			}
		}
		for (int j = 0; j < i; ++j)
			mp[a[i] + a[j]] = {i, j};
	}
	cout << "IMPOSSIBLE";
 
	return 0;
}
