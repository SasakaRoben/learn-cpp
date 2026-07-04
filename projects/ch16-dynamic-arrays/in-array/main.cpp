#include <iostream>
#include <vector>
#include <string_view>

std::string get_name() {
    std::cout << "Enter a name: ";
    std::string name {};
    std::cin >> name;
    
    return name;
}


template <typename T>
bool is_value_in_array(const std::vector<T>& arr, const T& value) {
    for (const auto& a : arr) {
        if (a == value) {
            return true;
        }
    }

    return false;
}

int main() {
    std::string user_name { get_name() };
    std::vector<std::string_view> names { "Alex", "Betty", "Caroline", "Dave",
                                          "Emily", "Fred", "Greg", "Holly" };
    
    // By explicitly specifying std::string_view as a function template 
    // argument, the compiler will implicitly convert username to 
    // `std::string_view` to match the parameter type.
    bool found { is_value_in_array<std::string_view>(names, user_name) };

    // The following is also okay. If we rely on template argument deduction 
    // instead, the compiler won't do implicit conversions, so we need to make 
    // sure `username` has the expected type.
    // bool found{isValueInArray(names, static_cast<std::string_view>(username))};

    if (found) {
        std::cout << user_name << " was found\n";
    }
    else {
        std::cout << user_name << " was not found\n";
    }

    return 0;
}
