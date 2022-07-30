#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
	vector<int> a(n);
	stack<int> stk;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		while (!stk.empty() && a[stk.top()] >= a[i]) 
			stk.pop();
		cout << (stk.empty() ? 0 : stk.top() + 1) << ' ';
		stk.push(i);
	}
 
	return 0;
}
