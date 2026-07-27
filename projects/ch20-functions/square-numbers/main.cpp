#include <iostream>
#include <vector>
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

int main() {
    
}
