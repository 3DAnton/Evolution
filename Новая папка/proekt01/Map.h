#ifndef MAP_H
#define MAP_H



#include<vector>

#include"object.h"
#include"Bot.h"


class Map
{
	public:
		Map();
		~Map() {}
	
		std::vector<std::vector<Object::ObjectType>> getPresentation();
	

private:
	std::vector<std::vector<Object*>> mField;
};

#endif // !MAP_H
