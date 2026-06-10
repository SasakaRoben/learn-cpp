// Ask user to enter 2 floating point numbers
// Ask user to enter +, -, *, /
// The program computes the answer and prints the results
// If invalid symbol entered, the program should print nothing
#include <iostream>

double get_number() {
    double x{};
    std::cin >> x;
    return x;
}

char get_operator() {
    char x{};
    std::cin >> x;
    return x; 
}

void print_result(double x, char operation, double y)
{
    double result{};

    if (operation == '+')
        result = x + y;
    else if (operation == '-')
        result = x - y;
    else if (operation == '*')
        result = x * y;
    else if (operation == '/')
        result = x / y;
    else       
        return;

    std::cout << x << ' ' << operation << ' ' << y << " is " << result << '\n';
}

int main() {
    std::cout << "Enter a double value: ";
    double x{get_number()};

    std::cout << "Enter a double value: ";
    double y{get_number()};

    std::cout << "Enter +, -, *, /: ";
    char op{get_operator()};

    print_result(x, op, y);

    return 0;
}
