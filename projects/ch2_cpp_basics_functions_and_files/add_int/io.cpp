#include <iostream>

int read_number() {
    int x{};
    std::cin >> x;
    return x;
}

void write_answer(int answer) {
    std::cout << answer << '\n';
}
