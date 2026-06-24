#include <iostream>

struct Monster {
    enum Type {
        ogre,
        dragon,
        orc,
        giant_spider,
        slime,
    };

    Type type {};
    std::string name {};
    int health {};
};

constexpr std::string_view get_monster_type_string(Monster::Type type)
{
    using enum Monster::Type;
    switch (type) {
        case ogre:          return "ogre";
        case dragon:        return "dragon";
        case orc:           return "orc";
        case giant_spider:  return "giant spider";
        case slime:         return "slime";

        default:            return "???";
    }
}

std::ostream& operator<<(std::ostream& out, Monster::Type type) {
    return out << get_monster_type_string(type);   
}

void print_monster(const Monster& monster) {
    std::cout << "This " << monster.type << " is named " << monster.name 
              << " and has " << monster.health << " health\n";
}

int main() {
    Monster ogre { Monster::ogre, "Torg", 145 };
    Monster slime { Monster::slime, "Blurp", 23 };

    print_monster(ogre);
    print_monster(slime);

    return 0;
}
