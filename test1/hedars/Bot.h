#ifndef BOT_H
#define BOT_H


#include "Object.h"
#include <vector>
#include <iostream>
class Bot :public Object
{
public:
	
	enum ActionType
	{
		NUN = 0,
		VOID =1,
		MOVE = 2,
		EAT = 3,
		LOOK = 4,
		MAKE = 5
	};
	Bot();
	~Bot();
	//Bot::ActionType move() ;
	char generateComand() const;
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
	//Direction mDirection;


};

#endif // !BOT_H
