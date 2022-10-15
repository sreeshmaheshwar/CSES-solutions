#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>

const int64_t INF = 1e16;

int main() {
    int n;
    std::cin >> n;
    std::vector<int64_t> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> pref[i];
        pref[i] += pref[i - 1];
    }
    std::vector<std::vector<int64_t>> cache(n, std::vector<int64_t>(n, INF));
    std::function<int64_t(int, int)> max_score = [&](int l, int r) -> int64_t {
        if (l > r) {
            return 0;
        } else if (cache[l][r] != INF) {
            return cache[l][r];
        } else {
            return cache[l][r] = pref[r + 1] - pref[l] - std::min(max_score(l + 1, r), max_score(l, r - 1));
        }
    };
    std::cout << max_score(0, n - 1);
    return 0;
}