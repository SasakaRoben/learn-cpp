#include <iostream>

class Fraction {
private:
    int m_numerator {};
    int m_denominator {};

public:
    explicit Fraction(int numerator, int denominator=1)
        : m_numerator { numerator }
        , m_denominator { denominator }
    {}

    void print() const {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    } 

    // We don't pass by value, because copying is slow
    // We shouldn't pass by non-const reference, because then our functions
    // won't work with r-values
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);
};

Fraction operator*(const Fraction& f1, const Fraction& f2) {
	return Fraction { f1.m_numerator * f2.m_numerator, 
                      f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value) {
	return Fraction { f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1) {
	return Fraction { f1 * value };
}

int main() {
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    return 0;
}
