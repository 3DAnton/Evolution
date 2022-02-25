#include "Bot.h"
/*пойти куда смотрит
  съесть куда смотрит
  осмтреться
  переделать куда то смотри
  */
#define raz 64
#define COMMAND_COUNT 6
#define START_HEALPH 90

Bot::Bot()
/*Object(Object::ObjectType::BOT),
mHealph (START_HEALPH),
mDirection(),*/
{};


int
Bot::getHealph() const
{
	return mHealph;
}

const Direction&
Bot::getDirection() const
{
	return mDirection;
}


char
Bot::generateComand() const
{
	int command = rand() % COMMAND_COUNT;
	switch (command)
	{
	case 0:
		command = Comands::BOT_GO;
		break;
	case 1:
		command = Comands::BOT_EAT;
		break;
	case 2:
		command = Comands::BOT_MAKE;
		break;
	case 3:
		command = Comands::BOT_LOOK;
		break;
	case 4:
		if (rand() % 2)	command = Comands::BOT_TURN_RIGHT;
		else			command = Comands::BOT_TURN_LEFT;
		break;
	case 5:
		if (rand() % 2) command = rand() % 10 + 1;
		else			command = -(rand() % 10 + 1);
		break;
	default:
		std::cout << "error command generating\n";
		command = 0;
		break;
	}
	return command;
}

void Bot::shiftProgramPtr(int aValue)
{
	mProgramPtr += aValue;
	while (mProgramPtr >= int(mProgram.size()))
	{
		mProgramPtr -= mProgram.size();
	}
	while (mProgramPtr < 0)
	{
		mProgramPtr += mProgram.size();
	}
}

Bot::ActionType
Bot::makeAction(Object::ObjectType aType)
{
	Bot::ActionType result = Bot::ActionType::NUN;

	if (aType != Object::ObjectType::NUN)
	{
		shiftProgramPtr(aType - 1);
	}

	switch (mProgram[mProgramPtr])
	{
	case BOT_GO:
		result = Bot::ActionType::MOVE;
		break;
	case BOT_EAT:
		result = Bot::ActionType::EAT;
		break;
	case BOT_MAKE:
		result = Bot::ActionType::MAKE;
		break;
	case BOT_LOOK:
		result = Bot::ActionType::LOOK;
		break;
	case BOT_TURN_RIGHT:
		++mDirection;
		result = Bot::ActionType::VOID;
		break;
	case BOT_TURN_LEFT:
		--mDirection;
		result = Bot::ActionType::VOID;
		break;
	default:
		if (mProgram[mProgramPtr] != 0)
		{
			shiftProgramPtr(mProgram[mProgramPtr]);
			result = Bot::ActionType::VOID;
		}
		else
		{
			std::cout << "bot program error\n";
		}
		break;
	}

	shiftProgramPtr(1);

	return result;
}


Bot::~Bot() {};


