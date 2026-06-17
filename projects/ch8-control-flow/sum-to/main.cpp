// sum_to() that takes an integer parameter, and returns the sum of all the numbers from 1 to the parameter

#include <iostream>

int sum_to(int value) {
	int sum {0};

	for (int i {1}; i <= value; ++i) {
		sum += i;
	}

	return sum;
}

int main() {
	std::cout << sum_to(5) << '\n';
}
