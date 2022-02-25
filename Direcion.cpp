#include "direction.h"

Direction::Direction()
{
	reset();
}

Direction::Direction(char aDirValue) :
	mValue(aDirValue)
{}


Pair<int>
Direction::shiftPair(const Pair<int>& aPair) const
{
	Pair<int> result = aPair;
	if (result.y % 2 == 0)
	{
		if (mValue > 2)			--result.x;
		else if (mValue == 1)	++result.x;
	}
	else
	{
		if (mValue == 4)		--result.x;
		else if (mValue < 3)	++result.x;
	}

	if (mValue == 0 || mValue == 5)			--result.y;
	else if (mValue == 2 || mValue == 3)	++result.y;

	return result;
}