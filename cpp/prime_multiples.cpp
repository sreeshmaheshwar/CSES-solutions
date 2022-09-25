#include <iostream>
#include <vector>

int main() {
    long long n, k;
    std::cin >> n >> k;
    std::vector<long long> primes(k);
    for (auto& p : primes)
        std::cin >> p;
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
    std::cout << union_size;
    return 0;
}

/*
Explanation:
    Let S_i be the set of integers <= n that are multiples of the ith prime.
    Then, our answer is the size of the union of all S_i together.
    So, we can apply the inclusion-exclusion principle.

    But how can we find the size of an intersection? In other words, given a subet
    of the primes provided, how can we find the number of integers <= n that are divisible
    by them all? Well, since they are all prime, a number is divisble by them all
    if and only if it is divisble by their product. 

    So, let P be the product of a given subset. Then, the size of the corresponding
    intersection is the number of multiples of P that are <= n, given by floor(n / P).

    We iterate over all (2^k - 1) non-empty subsets of the primes given. For each, we
    compute its product in O(k) and update our answer in O(1), as described above. 
    Thus, the time complexity of this approach is O(k * 2^k).
*/
