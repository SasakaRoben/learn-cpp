#include "MonsterGenerator.h"
#include "Monster.h"
#include "Random.h"

namespace MonsterGenerator {
    std::string_view getName(int n) {
        switch (n) {
            case 0:  return "Goguma";
            case 1:  return "Goshodo";
            case 2:  return "Cyclopes";
            case 3:  return "Dumby";
            case 4:  return "Oberon";
            case 5:  return "Dracula";
            default: return "???";
        }
    }

    std::string_view getRoar(int n) {
        switch (n) {
            case 0:  return "*ROAR*";
            case 1:  return "*peep*";
            case 2:  return "*squeal*";
            case 3:  return "*whine*";
            case 4:  return "*growl*";
            case 5:  return "*burp*";
            default: return "???";
        }
    }

	Monster generate() {
		 return Monster {
            static_cast<Monster::Type>(Random::get(0, Monster::max_monster_types-1)),
            getName(Random::get(0,5)),
            getRoar(Random::get(0,5)),
            Random::get(1, 100)
            };
	}

};
