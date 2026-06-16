// Use a switch statement to perform the appropriate mathematical operation on the integers, and return the result

#include <iostream>

int calculate(int x, int y, char op) {
    switch(op) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '%':
        return x % y;
    default:
        std::cout << "Invalid Operator\n";
        return 0;
    }
}

int get_integer() {
    int x {};
    std::cin >> x;
    return x;
}

char get_op() {
    char op {};
    std::cin >> op;
    return op;
}

int main() {
    std::cout << "Enter an integer: ";
    int x {get_integer()};

    std::cout << "Enter another integer: ";
    int y {get_integer()};

    std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
    char op {get_op()};

    int result {calculate(x, y, op)};
    std::cout << x << ' ' << op << ' ' << y << " is " << result << '\n';

    return 0;
}
