#include <array>
#include <iostream>
#include <string_view>

namespace Potion{
    enum Type {
        healing,
        mana,
        speed,
        invisibility,
        max_types,
    };

    constexpr std::array costs { 20, 30, 12, 50 };
    constexpr std::array types { healing, mana, speed, invisibility };
    constexpr std::array<std::string_view, max_types> names 
    { "healing", "mana", "speed", "invisibility" };

    static_assert(std::size(types) == max_types);
    static_assert(std::size(costs) == max_types);
    static_assert(std::size(costs) == max_types);
}

void shop () {
    std::cout << "Here is our selection for today:\n";

    for (auto p : Potion::types) {
        std::cout << p << ") " << Potion::names[p] << " costs "
                  << Potion::costs[p] << "\n";
    }
}
