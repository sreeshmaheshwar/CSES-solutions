#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    long long n;
    std::cin >> n;
    int k;
    std::cin >> k;
    std::vector<long long> primes(k);
    for (long long &prime : primes) {
        std::cin >> prime;
    }
    long long union_size = 0;
    for (int mask = 1; mask < (1 << k); ++mask) {
        int subset_size = 0;
        long long subset_product = 1;
        bool product_exceeds = false;
        for (int i = 0; i < k && !product_exceeds; ++i) {
            if (mask >> i & 1) {
                if (subset_product > n / primes[i]) {
                    product_exceeds = true;
                } else {
                    subset_product *= primes[i];
                    subset_size++;
                }
            }
        }
        // applying the inclusion-exclusion principle:
        if (!product_exceeds) {
            int sign = subset_size % 2 ? +1 : -1;
            long long intersection_size = n / subset_product;
            union_size += sign * intersection_size; 
        }
    }
    std::cout << union_size << '\n';
    
    return 0;
}