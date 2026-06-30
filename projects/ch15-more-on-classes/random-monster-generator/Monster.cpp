#include "Monster.h"

Monster::Monster(Type type, std::string_view name, 
        std::string_view roar, int hit_points)
        : m_type { type }
        , m_name { name }
        , m_roar { roar }
        , m_hit_points { hit_points }
{}

constexpr std::string_view Monster::get_type_string() const {
    switch (m_type) {
        case dragon:   return "dragon";
        case goblin:   return "goblin";
        case ogre:     return "ogre";
        case orc:      return "orc";
        case skeleton: return "skeleton";
        case troll:    return "troll";
        case vampire:  return "vampire";
        case zombie:   return "zombie";
        default:       return "???";
    }
}

void Monster::print() const {
    std::cout << m_name << " the " << get_type_string();

    if (m_hit_points <= 0) {
		std::cout << " is dead.\n"; 
	}
	else {
		std::cout << " has " << m_hit_points << " and says " << m_roar << '\n';
	} 
}

