// Ask for the name and age of two people, then prints which person is older.

#include <iostream>
#include <string>
#include <string_view>

int get_age(std::string_view name) {
    std::cout << "Enter the age of " << name << ": ";
    int age{};
    std::cin >> age;

    return age;
}

void print_older_person(int age1, int age2, std::string_view name1, 
                        std::string_view name2) {
    if (age1 > age2) {
        std::cout << name1 << " (age " << age1 << ") is older than " << name2
                  << " (age " << age2 << ")\n";
    }
    else {
        std::cout << name2 << " (age " << age2 << ") is older than " << name1
            << " (age " << age1 << ")\n";
    }
}

int main() {
    std::cout << "Enter the name of person #1: ";
    std::string name1 {};
    std::getline(std::cin >> std::ws, name1);

    int age1 { get_age(name1) }; 

    std::cout << "Enter the name of person #2: ";
    std::string name2 {};
    std::getline(std::cin >> std::ws, name2);

    int age2 { get_age(name2) };

    print_older_person(age1, age2, name1, name2);

    return 0;
}
