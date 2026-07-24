#include <iostream>

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
    

int main() {
    int x { get_integer() };
    int y { get_integer() };
    char op { get_operator() };

    std::cout << x << y << op << "\n";

    return 0;
}
