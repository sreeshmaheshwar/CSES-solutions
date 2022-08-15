#include <iostream>
const int MAX_X = 1e6;
int divisor_count[MAX_X + 1];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
 	
	for (int i = 1; i <= MAX_X; i++) 
		for (int j = i; j <= MAX_X; j += i) 
			divisor_count[j]++;

	int n; 
	std::cin >> n;
	while (n--) {
		int x; 
		std::cin >> x;
		std::cout << divisor_count[x] << '\n';
	}

	return 0;
}