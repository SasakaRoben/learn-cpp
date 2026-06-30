#include <iostream>

class Fraction {
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

public:
    explicit Fraction(int numerator=0, int denominator=1)
        : m_numerator { numerator }
        , m_denominator { denominator }
    {}

    Fraction multiply(const Fraction& f) {
        return Fraction { m_numerator * f.m_numerator, 
                          m_denominator * f.m_denominator };
    }

    void print_fraction() const {
        std::cout << m_numerator << "/" << m_denominator << '\n';
    }
};

int main() {
    Fraction f1 {1, 2};
    Fraction f2 {3, 4};

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).print_fraction();

    return 0;
}
