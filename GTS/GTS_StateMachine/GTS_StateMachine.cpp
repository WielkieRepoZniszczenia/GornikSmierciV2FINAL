
StateMachine* StateMachine::sm_StateMachine = NULL;


/// SINGLETON METHODS
int StateMachine::create()
{
	if(sm_StateMachine == NULL)
	{
		if(sm_StateMachine == NULL)
		{
			sm_StateMachine = new GTS::StateMachine;
		}
	}
	else
	{
		printf("Error. You can't create multiple instances of GTS_StateMachine.\n");
		return -1;
	}

	return 0;
}
StateMachine* StateMachine::get()
{
	return sm_StateMachine;
}
void StateMachine::destroy()
{
	if(sm_StateMachine != NULL)
	{
		delete sm_StateMachine;
		sm_StateMachine = NULL;
	}
}
///



/// CTOR / DTOR
StateMachine::StateMachine()
{
	m_lastState = NULL;
	m_currentState = NULL;
	m_nextState = NULL;
}
StateMachine::~StateMachine()
{
	//dtor
}
///



/// STATE SWITCHING
int StateMachine::set_nextState(GTS::State* next)
{
	if(next == NULL)
	{
		printf("Could not set next state. Null was passed as argument.\n");
		return -1;
	}

	m_nextState = next;

	return 0;
}
bool StateMachine::changed()
{
    if(m_nextState != NULL)
    	return true;

	return false;
}
int StateMachine::swtch_to_nextState()
{
	if(m_nextState == NULL)
	{
		printf("Could not set to nextState, because nextState is a null pointer.\n");
		return -1;
	}
	if(m_currentState != NULL)
	{
		m_currentState->clear();
	}

	m_lastState = m_currentState;

	m_currentState = m_nextState;

	m_nextState = NULL;

	if(m_currentState->set() != 0)
	{
		printf("Error during state setting.\n");
		return -1;
	}
	return 0;
}
///



/// GET STATES
GTS::State* StateMachine::get_currentState()
{
	return m_currentState;
}

GTS::State* StateMachine::get_lastState()
{
	return m_lastState;
}
///



