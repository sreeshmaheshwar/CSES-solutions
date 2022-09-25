#include <algorithm>
#include <iostream>
#include <vector>

struct project {
    int start, finish, reward;

    bool operator<(const project &other) const {
        return finish < other.finish;
    }
};

int main() {
    int N; 
    std::cin >> N; 
    std::vector<project> P(N);
    for (auto& [start, finish, reward] : P) 
        std::cin >> start >> finish >> reward;
    std::sort(P.begin(), P.end());
    
    std::vector<long long> max_reward(N + 1); // max_reward[i] is the maximum that can be earned from the first i projects 
    for (int i = 0; i < N; ++i) {
        int j = std::lower_bound(P.begin(), P.end(), project{0, P[i].start, 0}) - P.begin();
        max_reward[i + 1] = std::max(P[i].reward + max_reward[j], max_reward[i]);
    }
    std::cout << max_reward[N];
    return 0;
}