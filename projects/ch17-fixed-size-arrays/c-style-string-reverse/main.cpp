#include <iostream>

void print_c_string_backwards(const char str[]) {
    // We can't modify str this time (we need it later)
    // So we'll define a new pointer with the same address as str
    const char *ptr { str };

    // Find the null terminator
    while (*ptr != '\0') {
        ++ptr;
    }

    // Now walk backwards and print characters until ptr reaches
    // str again
    while (ptr-- != str) {
        std::cout << *ptr;
    }
}

int main() {
    print_c_string_backwards("Hello, world!");

    std::cout << '\n';

    return 0;
}
