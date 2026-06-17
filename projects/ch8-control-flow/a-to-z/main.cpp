// Prints out the alphabet along with their ASCII codes

#include <iostream>

int main() {
    char my_char {'a'};
    while (my_char <= 'z') {
        std::cout << my_char << ' ' <<  static_cast<int>(my_char) << '\n';
        my_char++;
    }

    return 0;
}
