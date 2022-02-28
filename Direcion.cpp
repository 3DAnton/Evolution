#include "direction.h"

#define DIRECTION_MIN_LIMIT 0
#define DIRECTION_MAX_LIMIT 5

Direction::Direction()
{
	reset();
}

Direction::Direction(char aDirValue) :
	mValue(aDirValue)
{}

Direction&
Direction::operator++() {
	mValue++;
	if (mValue > DIRECTION_MAX_LIMIT)
	{
		mValue -= DIRECTION_MAX_LIMIT + 1;
	}
	return *this;
}

Direction
Direction::operator++(int) {
	Direction tmp({ mValue });
	++(*this);
	return tmp;
}

Direction&
Direction::operator--() {
	mValue--;
	if (mValue < DIRECTION_MIN_LIMIT)
	{
		mValue += DIRECTION_MAX_LIMIT + 1;
	}
	return *this;
}

Direction
Direction::operator--(int) {
	Direction tmp({ mValue });
	--(*this);
	return tmp;
}

void
Direction::reset()
{
	mValue = std::rand() % 6;
}

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