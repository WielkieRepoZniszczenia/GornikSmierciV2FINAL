#include <iostream>
#include <string>

#include "GTS_Engine/GTS_Engine.h"


/// TEST RESOURCES
#include "GTS_Resource/GTS_TestButtons.h"
#include "GTS_Resource/GTS_TestResource.h"

/// TEST STATES
#include "GTS_State/GTS_TestState.h"


using namespace std;

int main(int argc, char* args[])
{
	/// STATE DECLARATION
	GTS::TestState testState;
	///


	/// ENGINE
    GTS::Engine::create();
    GTS::Engine* engine = GTS::Engine::get();
    if(engine == NULL)
    	return -1;

    if(engine->run(50, 50, 1600, 900, "testWindow", &testState) != 0)
        return -1;

	GTS::Engine::kill();
	///

    return 0;
}
