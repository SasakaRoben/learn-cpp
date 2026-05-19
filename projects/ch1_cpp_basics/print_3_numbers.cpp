// Ask the user to enter 3 values then print those values as a sentence
#include <iostream>

int main(void) {
    int x{};
    int y{};
    int z{};

    std::cout << "Enter three numbers: ";
    std::cin >> x >> y >> z;
    std::cout << "You entered " << x << ", " << y << ", " << "and " << z << '\n';

    return 0;
}
