#include <iostream>

bool validate_input();

int main() {
    int x{};

    while (true) {
        std::cout << "Enter an integer: ";
        std::cin >> x;

        if (validate_input())
            break;

        std::cout << "Invalid input, try again.\n";
    }

    std::cout << "You entered: " << x << '\n';

    int age;
    std::cout << "Enter age: ";
    std::cin >> age;
    if (!validate_input()) {
        std::cout << "Invalid input.\n";
    }

    double price;
    std::cout << "Enter price: ";
    std::cin >> price;
    if (!validate_input()) {
        std::cout << "Invalid input.\n";
    }

    char grade;
    std::cout << "Enter grade: ";
    std::cin >> grade;
    if (!validate_input()) {
        std::cout << "Invalid input.\n";
    }
}
