#include <iostream>

struct Fraction {
    int numerator {};
    int denominator {};
};

Fraction get_fraction() {
    Fraction fraction {};

    std::cout << "Enter a value for the numerator: ";
    std::cin >> fraction.numerator;

    std::cout << "Enter a value for the denominator: ";
    std::cin >> fraction.denominator;

    return fraction;
}

constexpr Fraction multiply_fraction(const Fraction& fraction1, 
    const Fraction fraction2) {
        return Fraction {fraction1.numerator * fraction2.numerator, 
                         fraction1.denominator * fraction2.denominator};
}

void print_result(const Fraction& fraction) {
    std::cout << "Your fractions multiplied together: " << fraction.numerator
              << "/" << fraction.denominator << '\n';
}

int main() {
    Fraction fraction1 { get_fraction() };
    Fraction fraction2 { get_fraction() };

    Fraction fraction { multiply_fraction(fraction1, fraction2) };
    print_result(fraction);

    return 0;
}
