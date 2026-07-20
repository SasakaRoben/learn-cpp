#include <array>
#include <iostream>
#include <string_view>
#include "Random.h"

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

class Player {
private:
    static constexpr int s_min_starting_gold { 80 };
    static constexpr int s_max_starting_gold { 120 };

    std::string m_name {};
    int m_gold {};
    std::array<int, Potion::max_types> m_inventory {};

public:
    explicit Player(std::string_view name):
        m_name { name },
        m_gold { Random::get(s_min_starting_gold, s_max_starting_gold) }
    {}

    int get_gold() const { return m_gold; }
};

std::string get_name() {
    std::cout << "Enter your name: ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);
    return name;
}

int main() {
    std::cout << "Welcome to Roscoe's Potion Emporium!\n";
    std::string name { get_name() };

    Player player { name };

    std::cout << "Hello, " << name << ", you have " << player.get_gold() 
              << " gold.\n\n";

    shop();

    std::cout << "\nThanks for shopping at Roscoe's Potion Emporium!\n";

    return 0;
}

