#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>

void fizzbuzzpop(int count) {

	// Made static so initialization is only done once
	static const std::vector divisors { 3, 5, 7, 11, 13, 17, 19 };
	static const std::vector<std::string_view> words { "fizz", "buzz", "pop",
	 												   "bang","jazz", "pow", 
													   "boom" 
													 };

	assert(divisors.size() == words.size() && "Array sizes don't match");

	for (int i{ 1 }; i <= count; ++i) {
		bool match {false};

		for (std::size_t index { 0 }; index < divisors.size(); ++index) {
    	
			if (i % divisors[index] == 0) {
				std::cout << words[index];
				match = true;
			}
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
