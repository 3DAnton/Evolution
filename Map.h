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
		

	//	void tabl(std::vector <std::vector<Object::ObjectType>> map);

private:
	std::vector<std::vector<Object::ObjectType>> mField;
};

#endif // !MAP_H