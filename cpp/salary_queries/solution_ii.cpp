#include <algorithm>
#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>

template <typename T> struct compressor {
  private:
    __gnu_pbds::gp_hash_table<T, int> compress_table;
    std::vector<T> values;
  public:
    compressor(std::vector<T> _values) : values(_values) {};
    size_t compress() {
        std::sort(values.begin(), values.end());
        values.erase(std::unique(values.begin(), values.end()), values.end());
        for (int i = 0; i < (int) values.size(); ++i) {
            compress_table[values[i]] = i;
        }
        return values.size();
    }
    int compressed_value(T value) {
        return compress_table[value];
    };    
};

template<typename T> struct fenwick_tree {
  private:
    std::vector<T> data;
    int n;
  public:
    fenwick_tree(int _n) : n(_n) {
        data.assign(n, T(0));
    }
    T prefix_sum(int r) {
        T res = T(0);
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += data[r];
        }
        return res;
    }
    T query(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
    void update_by(int i, T delta) {
        for (; i < n; i = i | (i + 1)) {
            data[i] += delta; 
        }
    }
};

struct process {
    int a, b;
    bool is_query;
};

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    auto input_values = p;
    std::vector<process> processes;
    for (int i = 0, a, b; i < q; ++i) {
        char type;
        std::cin >> type >> a >> b;
        bool is_query = false;
        if (type == '?') {
            is_query = true;
            input_values.push_back(a);
        }
        input_values.push_back(b);
        processes.push_back(process{a - !is_query, b, is_query});
    }
    compressor<int> C(input_values); // compress all values in input down to O(N + Q)
    fenwick_tree<int> ft(C.compress());
    for (int i = 0; i < n; ++i) {
        p[i] = C.compressed_value(p[i]);
        ft.update_by(p[i], +1);
    }
    for (auto [a, b, is_query] : processes) {
        if (is_query) {
            std::cout << ft.query(C.compressed_value(a), C.compressed_value(b)) << '\n';
        } else {
            ft.update_by(p[a], -1);
            p[a] = C.compressed_value(b);
            ft.update_by(p[a], +1);
        }
    }
    return 0;
}