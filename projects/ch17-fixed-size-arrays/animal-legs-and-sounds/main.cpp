#include <iostream>
#include <array>
#include <string>
#include <string_view>

namespace Animal {
    enum Type {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals,
    };

    struct Data {
        std::string_view name {};
        int legs {};
        std::string_view sound {};
    };

    constexpr std::array types { chicken, dog, cat, elephant, duck, snake };
    constexpr std::array data {
        Data{ "chicken",    2, "cluck" },
        Data{ "dog",        4, "woof" },
        Data{ "cat",        4, "meow" },
        Data{ "elephant",   4, "pawoo" },
        Data{ "duck",       2, "quack" },
        Data{ "snake",      0, "hissss" },
    };

    static_assert(std::size(types) == max_animals);
    static_assert(std::size(data) == max_animals);
};

// Teach operator>> how to input an Animal by name
// We pass animal by non-const reference so we can have 
// the function modify its value
std::istream& operator>> (std::istream& in, Animal::Type& animal) {
    std::string input {};
    std::getline(in >> std::ws, input);

    // See if we can find a match
    for (std::size_t index=0; index < Animal::data.size(); ++index) {
        if (input == Animal::data[index].name) {
            animal = static_cast<Animal::Type>(index);
            return in;
        }
    }

    // We didn't find a match, so input must have been invalid
    // so we will set input stream to fail state
    in.setstate(std::ios_base::failbit);
    return in;
}

void print_animal_data(Animal::Type type) {
    const Animal::Data& animal { Animal::data[type] };
    std::cout << "A " << animal.name << " has " << animal.legs 
              << " legs and says " << animal.sound << ".\n";
}

int main() {

    std::cout << "Enter an animal: ";
    Animal::Type animal_type {};
    std::cin >> animal_type;

    if (!std::cin) {
        std::cin.clear();
        std::cout << "That animal couldn't be found.\n\n";
    }
    else {
        print_animal_data(animal_type);
    }

    std::cout << "\nHere is the data for the rest of the animals:\n";

    for (const auto& animal : Animal::types) {
        if (animal_type == animal) {
            continue;
        }

        print_animal_data(animal);
    }

    return 0;
}

