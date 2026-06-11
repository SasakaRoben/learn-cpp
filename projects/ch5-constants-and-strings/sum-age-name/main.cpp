// Sum the age and number of characters in a name
// Spaces are included in the count
#include <iostream>
#include <string>

int get_age() {
    std::cout << "Enter your age: ";
    int x {};
    std::cin >> x;
    return x;
}

int main() {
    std::cout << "Enter your full name: ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);

    int age {get_age()};

    std::cout << "You age + length of name is: " << std::ssize(name) + age 
              << '\n';

    return 0;
}
