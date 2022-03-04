#include "Gui.h";
#include "Map.h";

int main()
{
	//sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	Map q(20, 32);
	Gui y;
	while (true)
	{
		y.draw(q.getPresentation());
		q.makeTurn();
	}
}