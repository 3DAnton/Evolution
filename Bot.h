#ifndef BOT_H
#define BOT_H


#include "Object.h"
#include "direction.h"


#include <vector>
#include <iostream>

class Bot :public Object
{
public:

	enum ActionType
	{
		NUN = 0,
		VOID = 1,
		MOVE = 2,
		EAT = 3,
		LOOK = 4,
		MAKE = 5
	};
	Bot();
	~Bot();
	//Bot::ActionType move() ;
	char generateComand() const;
	Bot::ActionType makeAction(Object::ObjectType aType);
	//const Direction& getDirection() const;

	int getHealph() const;
	const Direction& getDirection() const;

private:
	enum Comands
	{
		BOT_GO = 11,
		BOT_EAT = 12,
		BOT_MAKE = 13,
		BOT_LOOK = 14,
		BOT_TURN_RIGHT = 15,
		BOT_TURN_LEFT = 16,

	};
	std::vector<int> list_comand;

	int mHealph;
	Direction mDirection;

	int mProgramPtr;
	std::vector<int> mProgram;

	int generateComand() const;
	void shiftProgramPtr(int aValue);


};

#endif // !BOT_H