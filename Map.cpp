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
		mField[i][0] = new Object(Object::ObjectType::WALL);        // лево
		mField[i][31] = new Object(Object::ObjectType::WALL);       // право
	}
	for (int j = 0; j < mField[0].size(); ++j)
	{
		mField[0][j] = new Object(Object::ObjectType::WALL);        //низ
		mField[1][j] = new Object(Object::ObjectType::WALL);        //верх
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
				mField[i][j] = new Bot();
				mBotsCoord.push(Pair<int> (i, j));
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
			Pair<int> next = dir.shiftPair(cur);
			Object::ObjectType type = mField[next.x][next.y]->getType();
			switch (action)
			{
			case Bot::ActionType::NUN:
				std::cout << "bot action error\n";
				break;
			case Bot::ActionType::VOID:
				break;
			case Bot::ActionType::MOVE:
				if (type == Object::ObjectType::FOOD)
				{
					botPtr->feed(0.5);
					--mFoodtCounter;
				}
				else if (type == Object::ObjectType::POISON)
				{
					botPtr->poison(0.5);
					--mPoisonCounter;
				}

				if (type != Object::ObjectType::WALL &&
					type != Object::ObjectType::BOT)
				{
					setExictingObject(botPtr, next);
					mField[cur.x][cur.y] =
						new Object(Object::ObjectType::VOID);
					cur = next;
				}
				j = 100;
				break;
			case Bot::ActionType::EAT:
				if (type == Object::ObjectType::FOOD)
				{
					botPtr->feed(1);
					--mFoodtCounter;
					setNewObject(Object::ObjectType::VOID, next);
				}
				else if (type == Object::ObjectType::POISON)
				{
					botPtr->poison(1);
					--mPoisonCounter;
					setNewObject(Object::ObjectType::VOID, next);
				}
				j = 100;
				break;
			case Bot::ActionType::MAKE:
				if (type == Object::ObjectType::POISON)
				{
					++mFoodtCounter;
					--mPoisonCounter;
					setNewObject(Object::ObjectType::FOOD, next);
				}
				break;
			case Bot::ActionType::LOOK:
				argument = mField[next.x][next.y]->getType();
				break;
			}
		}
		if (!botPtr->aging())
		{
			mOldBots.push_front(botPtr);
			clearBotsMemory(8);
			mField[cur.x][cur.y] = new Object(Object::ObjectType::VOID);
		}
		else
		{
			mBotsCoord.push(cur);
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

void
Map::clearBotsMemory(char aValue)
{
	while (mOldBots.size() > aValue)
	{
		delete(mOldBots.back());
		mOldBots.pop_back();
	}
}


void
Map::setExictingObject
(
	Object* aObjectPtr,
	Pair<int>	aCoord
)
{
	delete(mField[aCoord.x][aCoord.y]);
	mField[aCoord.x][aCoord.y] = aObjectPtr;
}


void
Map::setNewObject
(
	Object::ObjectType	aType,
	Pair<int>		aCoord
)
{
	switch (aType)
	{
	case Object::VOID:
		setExictingObject(new Object(Object::ObjectType::VOID), aCoord);
		break;
	case Object::BOT:
		setExictingObject(new Bot(), aCoord);
		break;
	case Object::FOOD:
		setExictingObject(new Object(Object::ObjectType::FOOD), aCoord);
		break;
	case Object::POISON:
		setExictingObject(new Object(Object::ObjectType::POISON), aCoord);
		break;
	case Object::WALL:
		setExictingObject(new Object(Object::ObjectType::WALL), aCoord);
		break;
	default:
		setExictingObject(new Object(Object::ObjectType::NUN), aCoord);
		break;
	}
}