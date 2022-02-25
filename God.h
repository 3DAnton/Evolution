#ifndef GOD_H
#define GOD_H

#include "Gui.h"
#include "Map.h"

class God
{
public:
	God();
	~God();

	void run();
private:
	Map mWorld;
	Gui mView;

	bool pause = false;

};


#endif // GOD_H