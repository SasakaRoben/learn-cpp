#include <iostream>

// Return sum of all the values of x that have been passed to the function
int accumulate(int x) {
    static int accumulator {0};
    accumulator += x;
    return accumulator;
}

int main()
{
    std::cout << accumulate(4) << '\n'; // prints 4
    std::cout << accumulate(3) << '\n'; // prints 7
    std::cout << accumulate(2) << '\n'; // prints 9
    std::cout << accumulate(1) << '\n'; // prints 10

    return 0;
}
