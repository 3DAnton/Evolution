#ifndef MAP_H
#define MAP_H


#include <cstdlib>
#include <ctime>
#include<vector>

#include"object.h"
#include"Bot.h"


class Map
{
public:
	Map(int x_world_size, int y_world_size);
	~Map();
	
	std::vector<std::vector<Object::ObjectType>> getPresentation();



private:
	Bot::ActionType answer_for_bot(Object::ObjectType);
	std::vector<std::vector<Object*>> mField;
	

};

#endif // !MAP_H
