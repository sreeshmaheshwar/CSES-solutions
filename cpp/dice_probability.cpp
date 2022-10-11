#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(b + 1));
    dp[0][0] = 1.0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= b; ++j)
            for (int k = 1; k <= std::min(6, b - j); ++k)
                dp[i + 1][j + k] += dp[i][j] * (1 / 6.0);

    std::cout << std::fixed << std::setprecision(6) << std::accumulate(dp[n].begin() + a, dp[n].end(), 0.0);
    return 0;
}