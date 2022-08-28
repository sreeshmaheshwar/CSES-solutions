#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

template<typename T> struct fenwick_tree {
    std::vector<T> data;
    int n;
    fenwick_tree(int _n) : n(_n) {
        data.assign(n, T(0));
    }
    T prefix_sum(int r) {
        T res = T(0);
        for (; r >= 0; r = (r&(r+1))-1) res += data[r];
        return res;
    }
    T query(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
    void update_by(int i, T delta) {
        for (; i < n; i = i|(i+1)) data[i] += delta; 
    }
};

// coordinate compress all integer values in input to O(N + Q)
namespace compressor {
    struct custom_hash {
        std::size_t operator()(const int &key) const {
            static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
            uint64_t x = FIXED_RANDOM ^ key;
            return x ^ (x >> 16);
        }
    };
    std::unordered_map<int, int, custom_hash> compress;
    std::size_t compress_values(std::vector<int> values) {
        std::sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        for (int i = 0; i < (int) values.size(); ++i) compress[values[i]] = i;
        return values.size();
    }
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n), values;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        values.push_back(p[i]);
    }
    std::vector<std::pair<int, int>> to_process;
    std::vector<bool> is_query(q);
    for (int i = 0; i < q; ++i) {
        char type;
        int a, b;
        std::cin >> type >> a >> b;
        if (type == '?') {
            is_query[i] = true;
            values.push_back(a);
        }
        values.push_back(b);
        to_process.emplace_back(a - !is_query[i], b);
    }
    fenwick_tree<int> ft(compressor::compress_values(values));
    for (int i = 0; i < n; ++i) {
        p[i] = compressor::compress[p[i]];
        ft.update_by(p[i], +1);
    }
    for (int i = 0; i < q; ++i) {
        auto [a, b] = to_process[i];
        if (is_query[i]) {
            std::cout << ft.query(compressor::compress[a], compressor::compress[b]) << '\n';
        } else {
            ft.update_by(p[a], -1);
            p[a] = compressor::compress[b];
            ft.update_by(p[a], +1);
        }
    }
    return 0;
}