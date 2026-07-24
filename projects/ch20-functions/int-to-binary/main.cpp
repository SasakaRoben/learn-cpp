#include <iostream>

void print_binary(unsigned int x) {
    // We only recurse if n > 1, so this is our termination case for n == 0
    if (x > 1) {
        print_binary(x / 2);
    }

    // Print out the remainders (in reverse order)
    std::cout << x % 2;
}

int main() {
    int x {};
    std::cout << "Enter a positive integer: ";
    std::cin >> x;

    print_binary(static_cast<unsigned int>(x));

    std::cout << "\n";

    return 0;
}
