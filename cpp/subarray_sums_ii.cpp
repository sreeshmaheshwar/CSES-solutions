#include <iostream>
#include <map>
#include <vector>

long long count_subarrays_equal_to_x(std::vector<int>& a, int x) {
	std::map<long long, int> pref_sum_cnt;
	pref_sum_cnt[0] = 1;
	long long pref_sum = 0, answer = 0;
	for (int &element : a) {
		pref_sum += element;
		answer += pref_sum_cnt[pref_sum - x];
		pref_sum_cnt[pref_sum]++;
	}
	return answer;
}
 
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 
	int n, x;
	std::cin >> n >> x;
	std::vector<int> a(n);
	for (int &element : a) std::cin >> element;
	std::cout << count_subarrays_equal_to_x(a, x) << '\n';
 
	return 0;
}
