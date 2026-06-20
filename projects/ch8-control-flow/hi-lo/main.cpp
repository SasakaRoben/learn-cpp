#include <iostream>
#include "Random.h"

bool validate_input();

// Returns true if the user won, false if they lost
// We don't use the return value in this program, but it doesn't add complexity to have it, and may be useful in a future update
// (e.g. if we wanted to move the won/lost messages out of the function, or make other behavior depend on won/lost)
bool play_hi_lo(int guesses, int min, int max) {
	std::cout << "Let's play a game. I'm thinking of a number between " 
              << min << " and " << max << ". You have " << guesses 
              << " tries to guess what it is.\n";

	const int number { Random::get(min, max) };

	for (int count { 1 }; count <= guesses; ++count) {
		std::cout << "Guess #" << count << ": ";

		int guess{};

		while (true) {
        	std::cin >> guess;

			if (validate_input()) {
				if (guess < 1 || guess > 100) {
					std::cout << "The guess is out of bounds. Enter a number "
								"between 1 and 100: ";
					continue;
				}

				break;
			}

        	std::cout << "Invalid input, try again: ";
    	}


		if (guess > number) {
            std::cout << "Your guess is too high.\n";
        }
		else if (guess < number) {
            std::cout << "Your guess is too low.\n";
        }
		else {
			std::cout << "Correct! You win!\n";
			return true;
		}
	}

	std::cout << "Sorry, you lose. The correct number was " << number << '\n';
	return false;
}

bool play_again() {
	while (true) {
		char ch{};
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> ch;

		if (validate_input()) {
			switch (ch) {
				case 'y': return true;
				case 'n': return false;
			}
		}

		std::cout << "Invalid input. Please try again.\n";
	}
}

int main() {
	constexpr int guesses { 7 }; 
	constexpr int min     { 1 };
	constexpr int max     { 100 };

	do {
		play_hi_lo(guesses, min, max);
	} while (play_again());

	std::cout << "Thank you for playing.\n";

	return 0;
}
