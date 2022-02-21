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

Bot::~Bot() {};



