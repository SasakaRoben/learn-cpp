// Take two integers as input from user and display their sum

#include "io.h"
#include <iostream>

int main(void) {
    std::cout << "Enter the first integer: ";
    int x{read_number()};

    std::cout << "Enter the second integer: ";
    int y{read_number()};

    std::cout << x << " + " << y << " is ";
    write_answer(x + y);

    return 0;
}
