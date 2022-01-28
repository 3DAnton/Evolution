#ifndef GUI_H
#define GUI_H

#include <vector>;
#include "Object.h";


class Gui
{

public:
	Gui();
	~Gui();
	void draw(std::vector<std::vector<Object::ObjectType>> 
		result);
};





#endif // !GUI_H
