#include <iostream>

void print_binary(int x) {
    // Termination case
    if (x == 0) {
        return;
    }

    // Recurse to the next bit
    print_binary(x / 2);

    // Print out the remainders (in reverse order)
    std::cout << x % 2;
}

int main() {
    int x {};
    std::cout << "Enter a positive integer: ";
    std::cin >> x;

    print_binary(x);

    std::cout << "\n";

    return 0;
}
