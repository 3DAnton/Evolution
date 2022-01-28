#include "Map.h"

const int bot = 10;

Map::Map()
{
	for (int i = 0; i < mField.size(); ++i)
	{
		for (int j = 0; i < mField.size(); ++j)
		{
			mField[i][j] = new Object(Object::ObjectType::VOID);
		}
	}
}

std::vector<std::vector<Object::ObjectType>> Map::getPresentation()
{
	std::vector<std::vector<Object::ObjectType>> result;

	for (int i = 0; i < mField.size(); ++i)
	{
		for (int j = 0; i < mField.size(); ++j)
		{
			result[i][j] = mField[i][j] ->getType();
		}
	}

	return result;
}
