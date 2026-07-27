#include <iostream>
#include <vector>
#include <algorithm> // for std::find, std::min_element
#include <cmath> // for std::abs
#include "Random.h"

using Numbers = std::vector<int>;

namespace config {
    constexpr int multiplier_min { 2 };
    constexpr int multiplier_max { 4 };
}

// Generates "count" numbers starting at "start * start" and multiplies
// every square number by "multiplier"
Numbers generate_numbers(int start, int count, int multiplier) {
    Numbers numbers(static_cast<std::size_t>(count));

    for (int index { 0 }; index < count; ++ index) {
        std::size_t uindex { static_cast<std::size_t>(index) };
        numbers[uindex] = (start + index) * (start + index) * multiplier;
    }

    return numbers;
}

// Asks the user to input starting number, then generates array of numbers
Numbers setup_game() {
    int start {};
    std::cout << "Start where? ";
    std::cin >> start;

    int count {};
    std::cout << "How many? ";
    std::cin >> count;

    int multiplier 
    { Random::get(config::multiplier_min, config::multiplier_max) };

    std::cout << "I generated " << count << " square numbers. Do you know what "
              << " each number is after multiplying it by " << multiplier 
              << "?\n";

    return generate_numbers(start, count, multiplier);
}

// Returns the user's guess
int get_user_guess() {
    int guess {};

    std::cout << "> ";
    std::cin >> guess;

    return guess;
}

// Searches for the value "guess" in "numbers" and removes it.
// Returns true if the value was found. False otherwise.
bool find_and_remove(Numbers& numbers, int guess) {
    auto found { std::find(numbers.begin(), numbers.end(), guess) };

    if (found == numbers.end()) {
        return false;
    }

    numbers.erase(found);
    return true;
}

// Called when the user guesses a number correctly
void print_success(const Numbers& numbers) {
    std::cout << "Nice! ";

    if (numbers.size() == 0) {
        std::cout << "You found all numbers, good job!\n";
    }
    else {
        std::cout << numbers.size() << " number(s) left.\n";
    }
}

// Finds the value in "numbers" that is closest to "guess"
int find_closest_number(const Numbers& numbers, int guess) {
    return *std::min_element(numbers.begin(), numbers.end(), 
    [=](int a, int b) {
        return std::abs(a - guess) < std::abs(b - guess);
    });
}

// Called when the user guesses a number that's not in the numbers
void print_failure(const Numbers& numbers, int guess) {
    int closest { find_closest_number(numbers, guess) };

    std::cout << guess << " is wrong!\n";

    std::cout << "Try " << closest << " next time.\n";
}

int main() {
    Numbers numbers { setup_game() };

    while (true) {
        int guess { get_user_guess() };

        if (!find_and_remove(numbers, guess)) {
            print_failure(numbers, guess);
            break;
        }
        
        print_success(numbers);
        if (numbers.size() == 0) {
            break;
        }
    }

    return 0;
}
