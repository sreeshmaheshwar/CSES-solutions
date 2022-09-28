#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
  private:
  	int maximum;
  	std::vector<bool> prime;
  	std::vector<int> least_factor;
  	std::vector<int> freq, mult_freq;
  	std::vector<int> a;
  	int n;

  	void sieve() {
  		for (int i = 2; i <= maximum; ++i) {
			if (prime[i]) {
				least_factor[i] = i;
				for (int j = i + i; j <= maximum; j += i) {
					if (prime[j]) {
						prime[j] = false;
						least_factor[j] = i;
					}
				}
			}
		}
  	}
  	
  	std::vector<int> prime_factorise(int x) {
  		std::vector<int> ret;
  		while (x > 1) {
  			ret.push_back(least_factor[x]);
  			while (x % ret.back() == 0) 
  				x /= ret.back();
  		}
  		return ret;
  	}

  public:
  	Solution(std::vector<int> _a, int _n) : a(_a), n(_n) {
  		maximum = *std::max_element(a.begin(), a.end());
  		prime.assign(maximum + 1, true);
  		freq = mult_freq = least_factor = std::vector<int>(maximum + 1);
  		for (int x : a) 
  			freq[x]++;
  		for (int i = 2; i <= maximum; ++i)
  			for (int j = i; j <= maximum; j += i) 
  				mult_freq[i] += freq[j];
  		sieve();
  	}

  	int64_t solve() {
  		int64_t ret = (int64_t) n * n;
  		for (int x : a) {
  			if (x == 1) {
  				ret--;
  			} else {
  				auto pfs = prime_factorise(x);
  				int num_pfs = pfs.size();
  				for (int mask = 1; mask < (1 << num_pfs); ++mask) {
  					int subset_size = 0, product = 1;
  					for (int i = 0; i < num_pfs; ++i) {
  						if (mask >> i & 1) {
   							product *= pfs[i];
  							subset_size++;
  						}
  					}
  					ret += (subset_size % 2 ? -1 : +1) * mult_freq[product];
  				}
  			}
  		}
  		return ret / 2;
  	}
};

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int& x : a) 
		std::cin >> x;
	Solution solution(a, n);
	std::cout << solution.solve();
	return 0;
}