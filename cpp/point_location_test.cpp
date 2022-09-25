#include <iostream>
#include <vector>

struct point {
    long long x, y;

    point () {}

    point(long long _x, long long _y) : x(_x), y(_y) {}

    point operator-(const point& rhs) const {
        return point(x - rhs.x, y - rhs.y);
    }

    long long operator*(const point& rhs) const {
        return x * rhs.y - rhs.x * y;
    }
};

int main() {
    int t; 
    std::cin >> t;
    while (t--) {
        std::vector<point> points(3);
        for (auto& [x, y] : points) 
            std::cin >> x >> y;
        
        long long cross_prod = (points[2] - points[0]) * (points[1] - points[0]);
        std::cout << (cross_prod == 0 ? "TOUCH" : (cross_prod < 0 ? "LEFT" : "RIGHT")) << '\n';
    }
    return 0;
}