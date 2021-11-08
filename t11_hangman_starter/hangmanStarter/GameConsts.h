#pragma once

#include <string>

//dimensions in 2D that are whole numbers
struct Dim2Di
{
	int x, y;
};

/*
A box to put Games Constants in.
These are special numbers with important meanings (screen width, 
ascii code for the escape key, number of lives a player starts with,
the name of the title screen music track, etc.
*/
namespace GC
{
	//game play related constants to tweak
	const Dim2Di SCREEN_RES{ 1200,800 };

	const char ESCAPE_KEY{ 27 };
	const char ENTER_KEY{ 13 };

	const char NO_KEY = 0;		//default nothing was pressed
}


