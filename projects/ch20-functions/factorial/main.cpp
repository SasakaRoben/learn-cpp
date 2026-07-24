#include <iostream>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}

int main() {
    std::cout << factorial(7) << "\n";

    return 0;
}
