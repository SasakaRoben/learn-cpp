// Starting at 1, and counting upward, replace any number divisible only by 
// three with the word “fizz”, any number only divisible by five with the word 
// “buzz”, numbers divisible by seven should be replaced with “pop”. Also combine the words accordingly when a number is divisible by more than one divisor

#include <iostream>

void fizzbuzzpop(int count) {
	for (int i{ 1 }; i <= count; ++i) {
		bool match {false};

		if (i % 3 == 0) {
			std::cout << "fizz";
			match = true;
		}
		if (i % 5 == 0) {
			std::cout << "buzz";
			match = true;
		}
		if (i % 7 == 0) {
			std::cout << "pop";
			match = true;
		}
		if (!match) {
			std::cout << i;
		}
		std::cout << '\n';
	}
}

int main() {
    fizzbuzzpop(150);

    return 0;
}
