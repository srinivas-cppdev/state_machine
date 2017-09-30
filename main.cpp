#include <stdio.h>
#include "States.h"


shared_ptr<AbstractState> g_ptrStateMachine = nullptr;

void Transition(std::shared_ptr<AbstractState> newState)
{
	if(newState)
		g_ptrStateMachine = newState;
}

int main(int argc, char* argv[])
{
	// initial state
	g_ptrStateMachine = make_shared<State1>();

	Transition(g_ptrStateMachine->Event1());
	Transition(g_ptrStateMachine->Event2());
	Transition(g_ptrStateMachine->Event3());
	Transition(g_ptrStateMachine->Event2());
	Transition(g_ptrStateMachine->Event3());
	Transition(g_ptrStateMachine->Event3());

	if ( g_ptrStateMachine->CurrentState() == enumState2)
	{
		// do something
	}
	
	return 0;
}
