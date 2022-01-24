#ifndef EVOLUTION_MAP_H
#define EVOLUTION_MAP_H

#include <vector>
#include "Object.h"

class Map
{
public:
	Map();
	std::vector<std::vector<Object::ObjectType>> getPresentation();


private:
	std::vector<std::vector<Object*>> mField;;
};

#endif // 