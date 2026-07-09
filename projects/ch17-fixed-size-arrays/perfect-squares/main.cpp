#include <iterator>
#include <iostream>

namespace ProgramData {
    constexpr int perfect_squares[] { 0, 1, 4, 9 };
}

bool match_square(int input) {
    for (const auto& square : ProgramData::perfect_squares) {
        if (input == square) {
            return true;
        }
    }

    return false;
}

int main() {

    int input {};

    while(true) {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        std::cin >> input;

        if (input == -1) {
            std::cout << "Bye.\n";
            break;
        }

        if (match_square(input)) {
            std::cout << input << " is a perfect square\n";
        }
        else {
            std::cout << input << " is not a perfect square\n";
        }
    }

    return 0;
}
