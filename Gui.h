#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include <vector>;
#include "Object.h";


class Gui
{

public:
	//Gui(sf::RenderWindow& aWindow);
	Gui();
	~Gui();
	void draw(std::vector<std::vector<Object::ObjectType>> result);
private:
	
	sf::RenderWindow mWindow;
	sf::Text mText;
};





#endif // !GUI_H