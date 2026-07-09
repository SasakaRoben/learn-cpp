#include <iostream>

// str will point to the first letter of the C-style string
// Note that str points to a const char, so we cannot change the 
// values it points to
// However, we can point str at something else. This does not 
// change the value of the argument

void print_c_string(const char str[]) {
    // While we haven't encountered a null terminator
    while (*str != '\0') {
        // Print the current character
        std::cout << *str;

        // And use pointer arithmetic to move str to the next
        // character
        ++str;
    }
}

int main() {
    print_c_string("Hello, world!");

    std::cout << '\n';

    return 0;
}


