#include "Gui.h";
#include "Map.h";

int main()
{
	Map q(20,32);
	Gui y;
	y.draw(q.getPresentation());
}
