#ifndef DIRECTION_H
#define DIRECTION_H

#include <cstdlib>

struct Direction
{
public:
	Direction();
	Direction(char aDirValue);
	Direction& plus_1();
	Direction plus_1(int);

	Direction& minus_1();
	Direction minus_1(int);

};

#endif // DIRECTION_H
