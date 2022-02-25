#include "Map.h"

const int bot = 10;


/*Bot::ActionType Map::answer_for_bot(Object::ObjectType)
{

};*/

Map::Map(int x_world_size, int y_world_size) :
	mField(x_world_size, std::vector<Object*>(y_world_size, NULL))
{
	for (int i = 0; i < mField.size(); ++i)
	{
		for (int j = 0; j < mField[0].size(); ++j)
		{
			mField[i][j] = new Object(Object::ObjectType::VOID);
		}
	}

	for (int i = 0; i < mField.size(); ++i)
	{
		mField[i][0] = new Object(Object::ObjectType::WALL);        // ����
		mField[i][31] = new Object(Object::ObjectType::WALL);       // �����
	}
	for (int j = 0; j < mField[0].size(); ++j)
	{
		mField[0][j] = new Object(Object::ObjectType::WALL);        //���
		mField[1][j] = new Object(Object::ObjectType::WALL);        //����
	}

	srand(time(NULL));
	for (int i = 2; i < mField.size(); i++) {
		for (int j = 1; j < mField[0].size() - 1; ++j)
		{

			if (rand() % 5 == 1)
			{
				mField[i][j] = new Object(Object::ObjectType::FOOD);
			}
			if (rand() % 30 == 1)
			{
				mField[i][j] = new Object(Object::ObjectType::POISON);
			}
		}
	}

	srand(time(NULL) + 200);
	for (int i = 2; i < mField.size(); i++) {
		for (int j = 1; j < mField[0].size() - 1; ++j)
		{

			if (rand() % 50 == 1)
			{
				mField[i][j] = new Object(Object::ObjectType::BOT);
			}
		}
	}
}

std::vector<std::vector<Object::ObjectType>> Map::getPresentation()
{
	std::vector<std::vector<Object::ObjectType>>
		result(mField.size(), std::vector<Object::ObjectType>
			(mField[0].size(), Object::ObjectType::NUN));

	for (int i = 0; i < mField.size(); ++i)
	{
		for (int j = 0; j < mField[0].size(); ++j)
		{
			result[i][j] = mField[i][j]->getType();
		}
	}

	return result;
}

void Map::makeTurn()
{
	int count = mBotsCoord.size();
	for (int i = 0; i < count; i++)
	{
		Pair<int> cur = mBotsCoord.front();
		mBotsCoord.pop();

		Bot* botPtr = static_cast<Bot*>(mField[cur.x][cur.y]);
		Object::ObjectType argument = Object::ObjectType::NUN;
		for (int j = 0; j < 8; ++j)
		{
			Bot::ActionType action = botPtr->makeAction(argument);
			const Direction& dir = botPtr->getDirection();
			Pair<sint_16> next = dir.shiftPair(cur);





		}
	}
}

Bot::ActionType Map::answer_for_bot(Object::ObjectType)
{
	return Bot::ActionType();
}

void Map::reloadBotsCoordinates()
{
	for (int i = 1; i < mField.size() - 1; ++i)
	{
		for (int j = 1; j < mField[0].size() - 1; ++j)
		{
			if (mField[i][j]->getType() == Object::ObjectType::BOT)
			{
				mBotsCoord.push({ i, j });
			}
		}
	}
}

Map::~Map() {};