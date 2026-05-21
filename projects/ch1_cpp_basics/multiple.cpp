// Ask user for an integer and then tells them what double, and triple the
// input is

#include <iostream>

int main(void) {
    std::cout << "Enter an integer: ";

    int num{};
    std::cin >> num;

    std::cout << "Double that number is: " << num * 2 << '\n';
    std::cout << "Triple that number is: " << num * 3 << '\n';

    return 0;
}
