#pragma once
#include <memory>
#include <stack>

#include "State.h"

using namespace std;

typedef unique_ptr<State> stateRef;

class StateMachine {

public:
	StateMachine() { }
	~StateMachine() { }

	void AddState(stateRef newState, bool isReplacing = true);
	void RemoveState();

	void ProccedStateChanges();

	stateRef& GetActiveState();

private:

	stack<stateRef> _states;
	stateRef _newState;

	bool _isAdding;
	bool _isRemoving;
	bool _isReplacing;



};

