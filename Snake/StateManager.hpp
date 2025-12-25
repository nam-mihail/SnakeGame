#pragma once
#include <stack>
#include <memory>
#include "State.hpp"

class StateManager {
private:
    std::stack<std::unique_ptr<State>> states;

public:
    State* getCurrentState() {
        return states.top().get();
    }

    void pushState(std::unique_ptr<State> state) {
        states.push(std::move(state));
    }

    void popState(int count = 1) {
		while (count-- > 0 && !states.empty())
            states.pop();
    }

    bool empty() const {
        return states.empty();
    }

    void replaceState(std::unique_ptr<State> newState) {
		int count = 2;
        while (count-- > 0 && !states.empty())
            states.pop();

        states.push(std::move(newState));
    }
};