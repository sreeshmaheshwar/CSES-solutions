#include <iostream>
#include <map>
#include <vector>

int main() {
	int n, x;
	std::cin >> n >> x;
	std::map<long long, int> pref_sum_cnt;
	long long cur_pref_sum = 0, answer = 0;
	pref_sum_cnt[cur_pref_sum]++;
	for (int i = 0; i < n; ++i) {
		int element;
		std::cin >> element;
		cur_pref_sum += element;
		answer += pref_sum_cnt[cur_pref_sum - x];
		pref_sum_cnt[cur_pref_sum]++;
	}
	std::cout << answer << '\n';
	return 0;
}
