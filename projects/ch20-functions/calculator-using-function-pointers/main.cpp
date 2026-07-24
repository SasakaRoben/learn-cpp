#include <iostream>
#include <functional>

bool validate_input();

int get_integer() {
    int x {};

    while (true) {
        std::cout << "Enter an integer: ";
        std::cin >> x;

        if (validate_input()) {
            return x;
        }

        std::cout << "Invalid input. Try again.\n";
    }
}

char get_operator() {
    char op {};

    while (true) {
        std::cout << "Enter a mathematical operation (+,-,*,/): ";
        std::cin >> op;
        if (validate_input() 
            && (op == '+'
            || op == '-'
            || op == '/'
            || op == '*') ) {
            return op;
        }

        std::cout << "Invalid input. Try again.\n";
    }
}

// Pointer to a function that takes 2 integer parameters and returns an integer
using ArithmeticFunction = std::function<int(int, int)>;

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return x / y;
}

ArithmeticFunction get_arithmetic_function(char op) {
    switch (op) {
        case '+':
            return &add;
        case '-':
            return &subtract;
        case '*':
            return &multiply;
        case '/':
            return &divide;
    }

    return nullptr;
}

int main() {
    int x { get_integer() };
    int y { get_integer() };
    char op { get_operator() };
    ArithmeticFunction arithmetic_function { get_arithmetic_function(op) };

    if (arithmetic_function) {
        std::cout << x << " " << op << " " << y << " = " 
                  << arithmetic_function(x, y) << "\n";
    }
    
    return 0;
}
