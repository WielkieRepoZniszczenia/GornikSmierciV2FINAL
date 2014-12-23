#include <iostream>
#include <stdio.h>
#include <fstream>


#include "GTS_Engine/GTS_Engine.h"

#include "DIG_Game/DIG_Game.h"


int main(int argc, char* args[])
{
	DIG::Game diggers;

	if(GTS::Engine::create() != 0)
		return -1;

	GTS::Engine* engine = GTS::Engine::get();
	if(engine == NULL)
		return -1;

	if(engine->run(50, 50, 1600, 900, "Diggers", &diggers) != 0)
		return -1;

    return 0;
}
