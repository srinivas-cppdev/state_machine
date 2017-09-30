#include "States.h"

using namespace std;

#ifdef DEF_MAKE_UNIQUE
// using custom make_unique() - till upgrading to C++14
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
        return unique_ptr<T>( new T(std::forward<Args>(args)...));
}
#endif

AbstractState::AbstractState()
{
}

unique_ptr<AbstractState> AbstractState::Event1()
{
	return unique_ptr<AbstractState>();
}

unique_ptr<AbstractState> AbstractState::Event2()
{
	return unique_ptr<AbstractState>();
}

unique_ptr<AbstractState> AbstractState::Event3()
{
	return unique_ptr<AbstractState>();
}

AllStates AbstractState::CurrentState() const
{
	return enumStateInvalid;
}



// State 1

State1::State1()
{
}

unique_ptr<AbstractState> State1::Event1()
{
	return make_unique<State2>();
}

unique_ptr<AbstractState> State1::Event3()
{
	return make_unique<State3>();
}

AllStates State1::CurrentState() const
{
	return enumState1;
}


// State 2

State2::State2()
{
}

unique_ptr<AbstractState> State2::Event2()
{
	return unique_ptr<AbstractState>(); // no state change
}

unique_ptr<AbstractState> State2::Event3()
{
	return make_unique<State3>(); // state change
}

AllStates State2::CurrentState() const
{
	return enumState2;
}


// State 3

State3::State3()
{
}

unique_ptr<AbstractState> State3::Event1()
{
	return make_unique<State1>(); // state change
}

AllStates State3::CurrentState() const
{
	return enumState3;
}

