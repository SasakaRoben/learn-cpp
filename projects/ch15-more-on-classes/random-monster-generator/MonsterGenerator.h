#ifndef MONSTER_GENERATOR_H
#define MONSTER_GENERATOR_H

#include <iostream>
#include "Monster.h"

namespace MonsterGenerator {
    std::string_view getName(int n);
    std::string_view getRoar(int n);
	Monster generate();
};

#endif
