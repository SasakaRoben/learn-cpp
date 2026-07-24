#include <iostream>

int sum_digits(int number) {
    if (number == 0) {
        return 0;
    }

    return number % 10 + sum_digits(number / 10);
}

int main() {
    std::cout << sum_digits(93427) << "\n";

    return 0;
}
