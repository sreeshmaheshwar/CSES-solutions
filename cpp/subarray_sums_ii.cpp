#include <bits/stdc++.h>
using namespace std;
 
long long count_subarrays_equal_to_x(vector<int>& a, int x) {
	map<long long, int> pref_sum_cnt;
	pref_sum_cnt[0] = 1;
	long long pref_sum = 0, ret = 0;
	for (int& element : a) {
		pref_sum += element;
		ret += pref_sum_cnt[pref_sum - x];
		pref_sum_cnt[pref_sum]++;
	}
	return ret;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int& element : a) cin >> element;
	cout << count_subarrays_equal_to_x(a, x) << '\n';
 
	return 0;
}
