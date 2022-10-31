#include <iostream>
#include <vector>

const int MAX_X = 1e6;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> freq(MAX_X + 1);
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x;
        freq[x]++;
    }

    std::vector<long long> gcd_freq(MAX_X + 1);
    for (int i = MAX_X; i > 0; --i) {
        int cnt = 0;
        for (int j = i; j <= MAX_X; j += i)
            cnt += freq[j];

        gcd_freq[i] = 1LL * cnt * (cnt - 1) / 2;
        for (int j = 2 * i; j <= MAX_X; j += i)
            gcd_freq[i] -= gcd_freq[j];
    }

    std::cout << gcd_freq[1];
    return 0;
}