#ifndef MAP_H
#define MAP_H


#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>


#include"object.h"
#include"Bot.h"
#include "Domain.h"


class Map
{
public:
	Map(int x_world_size, int y_world_size);
	~Map();

	std::vector<std::vector<Object::ObjectType>> getPresentation();

	void makeTurn();


private:
	Bot::ActionType answer_for_bot(Object::ObjectType);
	std::vector<std::vector<Object*>> mField;
	void reloadBotsCoordinates();
	std::queue<Pair<int>> mBotsCoord;


};

#endif // !MAP_H