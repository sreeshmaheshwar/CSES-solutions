#include <iostream>
#include <vector>

struct Point {

	long long x, y;

	Point () {}

	Point(long long _x, long long _y) : x(_x), y(_y) {}

	Point operator -(const Point& rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}

	long long operator *(const Point& rhs) const {
		return x * rhs.y - rhs.x * y;
	}
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 
	int t; 
	std::cin >> t;
	while (t--) {
		std::vector<Point> p(3);
		for (int i = 0; i < 3; ++i) std::cin >> p[i].x >> p[i].y;
		long long cross_prod = (p[2] - p[0]) * (p[1] - p[0]);
		std::cout << (cross_prod == 0 ? "TOUCH" : (cross_prod < 0 ? "LEFT" : "RIGHT")) << '\n';
	}
 
	return 0;
}