#include <iostream>

int main() {
    std::cout << "Enter a number 0 through 9 (inclusive): ";
    int x{};
    std::cin >> x;

    if (x == 2 || x == 3 || x == 5 || x == 7) {
        std::cout << "The digit is prime\n";
    }
    else {
        std::cout << "The digit is not prime\n";
    }

    return 0;
}
