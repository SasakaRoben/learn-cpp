#include <iostream>
#include <string_view>

enum class Animal {
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};


constexpr std::string_view get_animal_name(Animal animal) {
    using enum Animal;

    switch (animal) {
        case pig:     return "pig";
        case chicken: return "chicken";
        case goat:    return "goat";
        case cat:     return "cat";
        case dog:     return "dog";
        case duck:    return "duck";
        default:      return "???";
    }
}

void print_number_of_legs(Animal animal) {
    using enum Animal;

    std::cout << "A " << get_animal_name(animal) << " has ";

    switch (animal) {
        case chicken:
        case duck:    
            std::cout << 2;          
            break;

        case pig:  
        case goat:
        case cat: 
        case dog:     
            std::cout << 4;          
            break;

        default:      
            std::cout << "???"; 
            break;
    }

    std::cout << " legs.\n";
}

int main() {
    print_number_of_legs(Animal::cat);
    print_number_of_legs(Animal::chicken);

    return 0;
}
