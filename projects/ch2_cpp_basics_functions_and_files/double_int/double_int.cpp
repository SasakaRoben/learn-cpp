// Reads and integer from user and prints double that integer to the console

#include <iostream>

int double_int(int number) {
    return number * 2;
}

int get_input() {
    int x{};
    std::cin >> x;
    return x;
}

int main(void) {
    std::cout << "Enter an integer: ";
    int x{get_input()};

    std::cout << "Double that integer is " << double_int(x) << '\n';

    return 0;
}
