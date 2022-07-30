#include <bits/stdc++.h>
using namespace std;
 
struct Vector {

	long long x, y;

	Vector () {};

	Vector(long long _x, long long _y) : x(_x), y(_y) {};

	Vector operator -(const Vector& rhs) const {
		return Vector(x - rhs.x, y - rhs.y);
	}

	long long operator *(const Vector& rhs) const {
		return x * rhs.y - rhs.x * y;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int test_cases; 
	cin >> test_cases;
	while (test_cases--) {
		vector<Vector> points(3);
		for (Vector &point : points) cin >> point.x >> point.y;
		long long cross_prod = (points[2] - points[0]) * (points[1] - points[0]);
		cout << (cross_prod == 0 ? "TOUCH" : (cross_prod < 0 ? "LEFT" : "RIGHT")) << '\n';
	}
 
	return 0;
}