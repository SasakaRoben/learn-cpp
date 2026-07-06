#include <vector>
#include <iostream>
#include <cassert>

namespace Items {
    enum Type {
        health_potion,
        torch,
        arrow,
        max_types,
    };
};

constexpr std::string_view get_item_name_plural(std::size_t type) {
    using enum Items::Type;

    switch (type) {
        case health_potion: return "health potions";
        case torch:         return "torches";
        case arrow:         return "arrows";

        default:            return "???";
    }
}

constexpr std::string_view get_item_name_singular(std::size_t type) {
    using enum Items::Type;

    switch (type) {
        case health_potion: return "health potion";
        case torch:         return "torch";
        case arrow:         return "arrow";

        default:            return "???";
    }
}

// Helper function to convert 'value' into an object of type std::size_t
// UZ is the suffix for literals of type std::size_t
template <typename T>
constexpr std::size_t toUZ(T value) {
    // Make sure T is an integral type
    static_assert(std::is_integral<T>() || std::is_enum<T>());

    return static_cast<std::size_t>(value);
}

void print_inventory_items(const std::vector<int>& inventory, 
                           Items::Type type) {
    bool plural { inventory[toUZ(type)] != 0 };
    std::cout << "You have " << inventory[toUZ(type)] << ' ';
    std::cout << (plural ? get_item_name_plural(type) 
                         : get_item_name_singular(type)) << '\n';
}

int count_total_items(const std::vector<int>& inventory) {
    int sum {};
    for (auto e : inventory) {
        sum += e;
    }

    return sum;
}

int main() {
    std::vector inventory { 1, 5, 10 };
    assert(Items::max_types == inventory.size() && "Arrays don't match");

    for (int i { 0 }; i < Items::max_types; ++i) {
        auto item { static_cast<Items::Type>(i) };
        print_inventory_items(inventory, item);
    }

    std::cout << "You have " << count_total_items(inventory) 
              << " total items\n";

    return 0;
}
