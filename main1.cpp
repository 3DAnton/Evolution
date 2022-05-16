#include "Gui.h";
#include "Map.h";
#include "God.h";
#include "sas.hpp";

#include <filesystem>
#include <iostream>

int xL, yL;


int main()
{
	std::cin >> WorldSize::x >> WorldSize::y;

	God g(WorldSize::x, WorldSize::y);
	g.run();
}