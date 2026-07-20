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

    constexpr std::array potion_costs { 20, 30, 12, 50 };
    constexpr std::array<std::string_view, max_types> potion_names 
    { "healing", "mana", "speed", "invisibility" };
}
