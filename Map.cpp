#include "Map.h"

const int BOT_DOWN_LIMIT = 8;
const int BOT_MULTIPLY_COUNT = 7;

const int bot     = 64;
const int food   = 550;
const int poison = 175;
const int wall   = 150;

Map::Map(int x_world_size, int y_world_size) :
	mField(x_world_size, std::vector<Object*>(y_world_size, NULL))    //29 52
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
		mField[i][51] = new Object(Object::ObjectType::WALL);       // право
	}
	for (int j = 0; j < mField[0].size(); ++j)
	{
		mField[0][j] = new Object(Object::ObjectType::WALL);        // низ
		mField[28][j] = new Object(Object::ObjectType::WALL);       // верх
	}

	srand(time(NULL) + 200);
	regenerate();
	createObjects(bot, Object::ObjectType::BOT);                   
	
	createObjects(1, Object::ObjectType::BOT);
	reloadBotsCoordinates();
}

void Map::createObjects(int aLim, Object::ObjectType aType)
{
	for (int cnt = 0; cnt < aLim; ++cnt)
	{
		setNewObject(aType, findVoid());
	}
}

Pair<int> Map::findVoid()                          
{
	Pair<int> result;
	do
	{
		result = Pair<int> (  rand() % mField.size(),  rand() % mField[0].size() );

	} while (mField[result.x][result.y]->getType() != Object::ObjectType::VOID);

	return result;
}

void Map::regenerate()
{
	for (int i = 1; i < mField.size() - 1; ++i)
	{
		for (int j = 1; j < mField[0].size() - 1; ++j)
		{
			setNewObject(Object::ObjectType::VOID, { i,j });
		}
	}

	createObjects(food,   Object::ObjectType::FOOD);
	createObjects(poison, Object::ObjectType::POISON);
	createObjects(wall,   Object::ObjectType::WALL);

	mFoodtCounter = food;
	mPoisonCounter = poison;
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
	Pair<int>	    	aCoord
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

    int  newPlantCount = 0;
	newPlantCount = (64*2 - mFoodtCounter) / 50;
	createNewPlant(Object::ObjectType::FOOD,
		mFoodSuitableCells, newPlantCount);
	mFoodtCounter += newPlantCount;

	newPlantCount = (64*3 - mPoisonCounter) / 50;
	createNewPlant(Object::ObjectType::POISON,
		mPoisonSuitableCells, newPlantCount);
	mPoisonCounter += newPlantCount;
}

void
Map::createNewPlant
(
	Object::ObjectType				aType,
	std::queue<Pair<int>>& aSuitableCells,
	int							aCount
)
{
	for (int i = 0; i < aCount; ++i)
	{
		if (aSuitableCells.empty())
		{
			getSuitableCells(aType, aSuitableCells);
		}
		if (aSuitableCells.empty()) break;

		Pair<int> cur = aSuitableCells.front();
		aSuitableCells.pop();
		if (mField[cur.x][cur.y]->getType() ==
			Object::ObjectType::VOID &&
			checkNeighbours(aType, cur)) setNewObject(aType, cur);
		else --i;
	}
}

void
Map::getSuitableCells
(
	Object::ObjectType				aType,
	std::queue<Pair<int>>& aContainer
)
{
	std::set<Pair<int>> setOfSuitableCells;
	Direction dir(0);
	for (int i = 1; i < mField.size() - 1; ++i)
	{
		for (int j = 1; j < mField[0].size() - 1; ++j)
		{
			Pair<int> cur(i, j);
			if (mField[cur.x][cur.y]->getType() ==
				Object::ObjectType::VOID &&
				checkNeighbours(aType, cur)) setOfSuitableCells.insert(cur);
		}
	}

	std::vector<std::vector<Pair<int>>> randomOrder(10);
	for (auto& i : setOfSuitableCells)
	{
		int num = std::rand() % randomOrder.size();
		randomOrder[num].push_back(i);
	}
	for (auto& i : randomOrder)
	{
		for (auto& j : i)
		{
			aContainer.push(j);
		}
	}
}

bool
Map::checkNeighbours
(
	Object::ObjectType				aType,
	Pair<int>					aCoord
)
{
	Direction dir(0);
	for (char k = 0; k < 6; ++k)
	{
		Pair<int> neighbour = dir.shiftPair(aCoord);
		if (mField[neighbour.x][neighbour.y]->getType() == aType)
		{
			return true;
		}
		++dir;
	}
	return false;
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

bool
Map::need_to_evolve() const
{
	return int (mBotsCoord.size()) <= BOT_DOWN_LIMIT;
}

void
Map::evolve()
{
	std::vector<Bot*> bots;

	while (!mBotsCoord.empty())
	{
		Pair<int> cur = mBotsCoord.front();
		mBotsCoord.pop();

		bots.push_back(static_cast<Bot*>(mField[cur.x][cur.y]));
		bots.back()->reset();
		mField[cur.x][cur.y] = new Object(Object::ObjectType::VOID);
	}

	regenerate();
	
	while (bots.size() < BOT_DOWN_LIMIT)
	{
		bots.push_back(static_cast<Bot*>(mOldBots.front()));
		bots.back()->reset();
		mOldBots.pop_front();
	}

	clearBotsMemory(0);

	for (auto& i : bots)
	{
		setExictingObject(i, findVoid());
	}

	for (char i = 0; i < BOT_MULTIPLY_COUNT; ++i)
	{
		for (auto& j : bots)
		{
			Bot* new_bot = new Bot(*j);
			new_bot->evolve((i - 1) < 0 ? 0 : (i - 1));
			setExictingObject(static_cast<Object*> (new_bot), findVoid());
		}
	}
	reloadBotsCoordinates();
}
