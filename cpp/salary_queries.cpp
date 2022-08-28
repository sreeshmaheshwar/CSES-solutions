#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<
std::pair<int, int>, 
__gnu_pbds::null_type, 
std::less<std::pair<int, int>>, 
__gnu_pbds::rb_tree_tag, 
__gnu_pbds::tree_order_statistics_node_update> 
ordered_set;

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n);
    ordered_set s;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        s.insert({p[i], i});
    }
    while (q--) {
        char type;
        int a, b;
        std::cin >> type >> a >> b;
        if (type == '!') {
            a--;
            s.erase({p[a], a});
            p[a] = b;
            s.insert({p[a], a});
        } else {
            std::cout << s.order_of_key({b + 1, -1}) - s.order_of_key({a, -1}) << '\n';
        }
    }
    return 0;
}