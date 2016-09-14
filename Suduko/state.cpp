//
//  state.cpp
//  Suduko
//
//  Created by Xueqi Liu on 9/14/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#include "state.hpp"

// -----------------------------------------------------------------------------
State::State(char initChar) : value(initChar) {
    if (!checkInput(value)) {
        fatal("Wrong input for State Constructor: %c\nExpects 1 to 9", value);
    }
    if (value == '-') {
        possibilities = POSSIBLE_ALL;
        fixed = false;
    } else if (value != '0' && isdigit(value)) {
        possibilities = POSSIBLE_NONE;
        fixed = true;
    }
}

// -----------------------------------------------------------------------------
// set state to ch. if success, return true, else return false;
bool State::move(char ch) {
    if (fixed) {
        // do we call fatal here? fatal will terminate the program
        // but we still need give user chance to continue
        fatal("Could not change the value");
    }
    if (!checkInput(ch)) {
        cerr << "Wrong input for State value. Expects 1 to 9" << endl;
        return false;
    }
    // check if value is possible?
    if (valueIsPossible(ch))
        value = ch;
    else {
        // do we give hint to player?
        cerr << "Could not put " << ch << " here." << endl;
    }
    return true;
}

// -----------------------------------------------------------------------------
// behavior:
//   set state empty
void State::remove() {
    if (fixed) {
        // do we call fatal here? fatal will terminate the program
        // but we still need give user chance to continue
        fatal("Could not change the value");
    }
    value = '-';
    // emit value changed signal?
    
}

// -----------------------------------------------------------------------------
// print state possibilities
void State::print(ostream &out) const {
    out << value << " ";
    for (int k = 1; k < 10; ++k) {
        if ((possibilities >> k) & 1) out << k;
        else cout << '-';
    }
}


// -----------------------------------------------------------------------------
ostream& operator<<(ostream& out, const State& state) {
    state.print(out);
    return out;
}