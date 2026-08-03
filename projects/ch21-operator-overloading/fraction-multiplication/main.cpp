#include <iostream>
#include <numeric>

class Fraction {
private:
    int m_numerator {};
    int m_denominator {};

public:
    explicit Fraction(int numerator=0, int denominator=1)
        : m_numerator { numerator }
        , m_denominator { denominator }
    {
        // We put reduce() in the constructor to ensure any fractions we make
        // get reduced!
        // Since all of the overloaded operators create new Fractions, we can
        // guarantee this will get called here
        reduce();
    }

    void reduce () {
        int gcd{ std::gcd(m_numerator, m_denominator) };

        // Make sure we don't try to divide by 0
		if (gcd) {
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
    }

    void print() {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    } 

    // We don't pass by value, because copying is slow
    // We shouldn't pass by non-const reference, because then our functions
    // won't work with r-values
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);
    friend std::ostream& operator<< (std::ostream& out, const Fraction& f);
    friend std::istream& operator>> (std::istream& out, Fraction& f);
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

std::ostream& operator<< (std::ostream& out, const Fraction& f) {
    out << f.m_numerator << "/" << f.m_denominator;

    return out;
}

std::istream& operator>> (std::istream& in, Fraction& f) {
    int numerator {};
    char ignore {};
    int denominator {};

    in >> numerator >> ignore >> denominator;

    // If our denominator is semantically invalid, set failure mode manually
    if (denominator == 0) { 
        in.setstate(std::ios_base::failbit);
    }

    // If we're not in failure mode, update our object to the extracted values
    if (in) {
        f = Fraction{numerator, denominator};
    }

    return in;
}

int main() {
    Fraction f1 {};
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2 {};
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    // note: The result of f1 * f2 is an r-value
    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

    return 0;
}
