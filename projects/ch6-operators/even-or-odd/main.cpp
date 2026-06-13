// Determines whether a number is even or odd
#include <iostream>

int get_integer() {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

constexpr bool is_even(int x) {
    return ((x % 2) == 0);
}

int main() {
    int x{ get_integer() };
    if (is_even(x)) {
        std::cout << x << " is even\n";
    }
    else {
        std::cout << x << " is odd\n";
    }

    return 0;
}
