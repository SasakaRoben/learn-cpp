// Get the number of apples the user has in words...?
#include <iostream>
#include <string_view>

std::string_view get_quantity_phrase(int apples) {
    if (apples < 0) {
        return "negative";
    }
    else if (apples == 0) {
        return "no";
    }
    else if (apples == 1) {
        return "a single";
    }
    else if (apples == 2) {
        return "a couple of";
    }
    else if (apples == 3) {
        return "a few";
    }
    else {
        return "many";
    }
}

std::string_view get_apples_pluralized(int apples) {
    return (apples == 1) ? "apple" : "apples";
}

int main() {
    constexpr int mary_apples { 3 };
    std::cout << "Mary has " << get_quantity_phrase(mary_apples) << ' ' << get_apples_pluralized(mary_apples) << ".\n";

    std::cout << "How many apples do you have? ";
    int num_apples{};
    std::cin >> num_apples;

    std::cout << "You have " << get_quantity_phrase(num_apples) << ' ' << get_apples_pluralized(num_apples) << ".\n";

    return 0;
}
