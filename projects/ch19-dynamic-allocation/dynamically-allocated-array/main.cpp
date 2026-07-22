#include <iostream>
#include <string>
#include <algorithm>

std::size_t get_name_count() {
    std::cout << "How many names would like to enter? ";
    std::size_t length {};
    std::cin >> length;
    return length;
}

void get_names(std::string* names, std::size_t length) {
    for (std::size_t index { 0 }; index < length; ++index) {
        std::cout << "Enter name #" << index + 1 << ": ";
        std::getline(std::cin >> std::ws, names[index]);
    }
}

void print_names(std::string* names, std::size_t length) {
    std::cout << "\nHere is your sorted list: \n";
    for (std::size_t index { 0 }; index < length; ++index) {
        std::cout << "Name #" << index + 1 << ": " << names[index] << "\n";
    }
}

int main() {
    std::size_t length { get_name_count() };

    auto* names { new std::string[length]{} };

    get_names(names, length);

    std::sort(names, names + length);

    print_names(names, length);

    delete[] names;

    return 0;
}
