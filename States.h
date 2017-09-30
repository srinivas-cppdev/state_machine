#pragma once

#include <memory>

using namespace std;

enum AllStates
{
	enumStateInvalid = -1,
	enumState1 = 0,
	enumState2,
	enumState3,
	enumStateMax
};

class AbstractState
{
	public:
	AbstractState();
	virtual ~AbstractState() {};

	// All events that act on state must be declared here, event should return ptr to AbstractState

	virtual unique_ptr<AbstractState> Event1();
	virtual unique_ptr<AbstractState> Event2();
	virtual unique_ptr<AbstractState> Event3();

	virtual AllStates  CurrentState() const;
};

class State1 : public AbstractState
{
	public:
	State1();

	virtual unique_ptr<AbstractState> Event1();
	virtual unique_ptr<AbstractState> Event3();
	virtual AllStates CurrentState() const;
};

class State2 : public AbstractState
{
	public:
	State2();

	virtual unique_ptr<AbstractState> Event2();
	virtual unique_ptr<AbstractState> Event3();
	virtual AllStates CurrentState() const;
};

class State3 : public AbstractState
{
	public:
	State3();

	virtual unique_ptr<AbstractState> Event1();
	virtual AllStates CurrentState() const;
};

