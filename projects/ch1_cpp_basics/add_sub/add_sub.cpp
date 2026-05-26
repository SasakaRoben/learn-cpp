// The program ask the user to enter 2 numbers and then tells the user the 
// result of adding and subtracting the 2 numbers

#include <iostream>

int main(void) {

    std::cout << "Enter an integer: ";
    int n1{};
    std::cin >> n1;

    std::cout << "Enter another integer: ";
    int n2{};
    std::cin >> n2;

    std::cout << n1 << " + " << n2 << " is " << n1 + n2 << '\n';
    std::cout << n1 << " - " << n2 << " is " << n1 - n2 << '\n';

    return 0;
 }
