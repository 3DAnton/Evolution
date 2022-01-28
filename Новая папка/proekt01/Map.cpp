#include "Map.h"

const int bot = 10;

Map::Map():
mField(20, std::vector<Object*>(32, NULL))
{
	for (int i = 0; i < mField.size(); ++i)
	{
		for (int j = 0; j < mField.size(); ++j)
		{
			mField[i][j] = new Object(Object::ObjectType::VOID);
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
		for (int j = 0; j < mField.size(); ++j)
		{
			result[i][j] = mField[i][j]->getType();
		}
	}

	return result;
}

Map::~Map() {};
