// Asks the user to enter two integers, one named smaller, the other named larger. If the user enters a smaller value for the second integer, use a block and a temporary variable to swap the smaller and larger values. Then print the values of the smaller and larger variables.
// When you print the values, smaller should hold the smaller input and larger the larger input, no matter which order they were entered in.


#include <iostream>
#include <utility> // For std::swap()

int get_integer() {
    int smaller{};
    std::cin >> smaller;
    return smaller;
}

int main() {
    std::cout << "Enter an integer: ";
    int smaller{get_integer()};

    std::cout << "Enter a larger integer: ";
    int larger{get_integer()};

    if (larger < smaller) {
        std::cout << "Swapping values\n";
        std::swap(larger, smaller);
    }

    std::cout << "The smaller value is: " << smaller << '\n';
    std::cout << "The larger value is: " << larger << '\n';

    return 0;
}
