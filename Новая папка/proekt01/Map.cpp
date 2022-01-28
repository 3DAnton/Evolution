#include "Map.h"


Map::Map()
{

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; i < 10; ++j)
		{

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
			result[i][j] = mField[i][j];
		}
	}

	return result;
}
