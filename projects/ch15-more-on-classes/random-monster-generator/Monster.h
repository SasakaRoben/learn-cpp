#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

class Monster {
public:
	enum Type {
	dragon,
	goblin,
	ogre,
	orc,
	skeleton,
	troll,
	vampire,
	zombie,
	max_monster_types,
	};


private:
	Type m_type {};
	std::string m_name { "???" };
	std::string m_roar { "???" };
	int m_hit_points {};

public:
	Monster(Type type, std::string_view name, std::string_view roar,
			int hit_points);
            
	constexpr std::string_view get_type_string() const;
    void print() const; 
};

#endif
