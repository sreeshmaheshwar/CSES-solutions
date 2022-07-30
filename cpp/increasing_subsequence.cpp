#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> subseq;
	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(subseq.begin(), subseq.end(), a[i]);
		if (it == subseq.end()) {
			subseq.push_back(a[i]);
		} else {
			*it = a[i];
		}
	}
	cout << (int) subseq.size() << '\n';
 
	return 0;
}