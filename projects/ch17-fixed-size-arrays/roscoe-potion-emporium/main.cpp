#include <array>
#include <iostream>
#include <string_view>
#include "Random.h"
bool validate_input();

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

    // Returns false if can't afford, true if purchased
    bool buy_potion(Potion::Type type) {
        if (m_gold < Potion::costs[type]) {
            return false;
        }

        m_gold -= Potion::costs[type];
        ++m_inventory[type];
        return true;
    } 

    int get_gold() const { return m_gold; }
};

int char_num_to_int(char c) {
    return c - '0';
}

Potion::Type which_potion() {
    std::cout << "Enter the number of the potion you'd like to buy, "
              << "or 'q' to quit: ";

    char input {};

    while(true) {
        std::cin >> input;

        if (input == 'q') {
            return Potion::max_types;
        }

        int val { char_num_to_int(input) };
        if (validate_input() && (val >= 0 && val < Potion::max_types)) {
            return static_cast<Potion::Type>(input);
        }
        else {
            std::cout << "Invalid input, try again: ";
        }
    }
}


void shop (Player& player) {
    while(true) {
        std::cout << "Here is our selection for today:\n";

        for (auto p : Potion::types) {
            std::cout << p << ") " << Potion::names[p] << " costs "
                    << Potion::costs[p] << "\n";
        }

        Potion::Type which { which_potion() };
        if (which == Potion::max_types) {
            return;
        }

        bool success { player.buy_potion(which) };
        if (!success) {
            std::cout << "You cannot afford that.\n\n";
        }
        else {
            std::cout << "You purchased a potion of " << Potion::names[which]
                      << ". You have " << player.get_gold() 
                      << " gold remaining.\n";
        }
    }
}

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

    shop(player);

    std::cout << "\n";

    std::cout << "\nThanks for shopping at Roscoe's Potion Emporium!\n";

    return 0;
}

