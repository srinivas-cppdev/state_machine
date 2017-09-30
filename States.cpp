#include "States.h"

using namespace std;

AbstractState::AbstractState()
{
}

shared_ptr<AbstractState> AbstractState::Event1()
{
	return shared_ptr<AbstractState>();
}

shared_ptr<AbstractState> AbstractState::Event2()
{
	return shared_ptr<AbstractState>();
}

shared_ptr<AbstractState> AbstractState::Event3()
{
	return shared_ptr<AbstractState>();
}

AllStates AbstractState::CurrentState() const
{
	return enumStateInvalid;
}



// State 1

State1::State1()
{
}

shared_ptr<AbstractState> State1::Event1()
{
	return make_shared<State2>();
}

shared_ptr<AbstractState> State1::Event3()
{
	return make_shared<State3>();
}

AllStates State1::CurrentState() const
{
	return enumState1;
}


// State 2

State2::State2()
{
}

shared_ptr<AbstractState> State2::Event2()
{
	return shared_ptr<AbstractState>(); // no state change
}

shared_ptr<AbstractState> State2::Event3()
{
	return make_shared<State3>(); // state change
}

AllStates State2::CurrentState() const
{
	return enumState2;
}


// State 3

State3::State3()
{
}

shared_ptr<AbstractState> State3::Event1()
{
	return make_shared<State1>(); // state change
}

AllStates State3::CurrentState() const
{
	return enumState3;
}

