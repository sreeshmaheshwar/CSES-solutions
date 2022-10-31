#include <cstdint>
#include <iostream>
#include <vector>

struct point {
    int x, y;

    point operator-(const point& other) const {
        return point{x - other.x, y - other.y};
    }

    int64_t operator*(const point& other) const {
        return int64_t(x) * other.y - int64_t(other.x) * y;
    }

    int64_t cross(const point& a, const point& b) const {
        return (a - *this) * (b - *this);
    }

    int64_t dot(const point& other) const {
        return int64_t(x) * other.x + int64_t(y) * other.y;
    }

    bool on_segment(const point& a, const point& b) const {
        return !cross(a, b) && (a - *this).dot(b - *this) <= 0;
    }

    bool inside_polygon(const std::vector<point>& polygon, bool& on_boundary) {
        int n = (int) polygon.size();
        bool inside = false;
        for (int i = 0; i < n; ++i) {
            point p = polygon[i], q = polygon[(i + 1) % n];
            if (on_segment(p, q)) on_boundary = true;
            inside ^= ((y < p.y) - (y < q.y)) * cross(p, q) > 0;
        }
        return inside;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<point> polygon(n);
    for (auto& [x, y] : polygon)
        std::cin >> x >> y;

    for (int i = 0, x, y; i < m; ++i) {
        std::cin >> x >> y;        
        bool boundary = false, inside = point{x, y}.inside_polygon(polygon, boundary);
        std::cout << (boundary ? "BOUNDARY" : (inside ? "INSIDE" : "OUTSIDE")) << std::endl;
    }
    return 0;
}