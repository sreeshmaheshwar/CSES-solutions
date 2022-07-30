#include <bits/stdc++.h>
using namespace std;
const int MXSUM = 1e5 + 5;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
	bitset<MXSUM> sums;
	sums[0] = 1;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		sums |= (sums << x);
	}
	cout << sums.count() - 1 << '\n';
	for (int i = 1; i < MXSUM; ++i) {
		if (sums[i])
			cout << i << " ";
	}
 
	return 0;
}