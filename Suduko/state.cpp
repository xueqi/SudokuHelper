//
//  state.cpp
//  Suduko
//
//  Created by Xueqi Liu on 9/14/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#include "state.hpp"

// ---------------------------------------------------------------------------
State::State(char initChar) : value(initChar) {
    if (!validInput(value)) {
        possibilities = POSSIBLE_NONE;
        say("Wrong input for State Constructor: %c\nExpects 1 to 9", value);
        return;
    }
    if (value == '-') {
        possibilities = POSSIBLE_ALL;
        fixed = false;
    } else if (value != '0' && isdigit(value)) {
        possibilities = POSSIBLE_NONE;
        fixed = true;
    }
}

// ---------------------------------------------------------------------------
// set state to ch. if success, return true, else return false;
bool State::move(char ch) {
    if (fixed) {
        // do we call fatal here? fatal will terminate the program
        // but we still need give user chance to continue
        say("Could not change the value");
        return false;
    }
    if (!validInput(ch)) {
        cerr << "Wrong input for State value. Expects 1 to 9" << endl;
        return false;
    }
    // check if value is possible?
    if (valueIsPossible(ch))
        value = ch;
    else {
        // do we give hint to player?
        cerr << "Could not put " << ch << " here." << endl;
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// behavior:
//   set state empty
void State::remove() {
    if (fixed) {
        // do we call fatal here? fatal will terminate the program
        // but we still need give user chance to continue
        say("Could not change the value");
        return;
    }
    value = '-';
    // emit value changed signal?
    
}

// ---------------------------------------------------------------------------
// print state possibilities
ostream& State::print(ostream &out) const {
    out << "Value " << value << ", Possible: ";
    for (int k = 1; k < 10; ++k) {
        if ((possibilities >> k) & 1) out << k;
        else cout << '-';
    }
    return out;
}

// ---------------------------------------------------------------------------
// Square
Square::Square(char initChar, sint row, sint col)
    : State(initChar), row(row), col(col) {
    cerr << "Square " << row << ", " << col << " constructed"<< endl;
        
}

// ---------------------------------------------------------------------------
Square::Square() : State('-'), row(0), col(0) {
    cerr << "Constructing empty square " << row << ", " << col << endl;
}

// ---------------------------------------------------------------------------
Square::~Square() {
    cerr << "Deleting Square " << row << ", " << col << endl;
}

// ---------------------------------------------------------------------------
ostream& Square::print(ostream& out) const {
    out << "Square [" << row << ", " << col << "] ";
    State::print(out);
    return out;
}

