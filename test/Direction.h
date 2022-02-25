#ifndef DIRECTION_H
#define DIRECTION_H

#include <cstdlib>

#include "Domain.h"

struct Direction
{
public:
	Direction();
	Direction(char aDirValue);
	Direction& plus_1();
	Direction plus_1(int);

	Direction& minus_1();
	Direction minus_1(int);

	void reset();

	Pair<int> shiftPair(const Pair<int>& aPair) const;
private:
	char mValue;
};

#endif // DIRECTION_H