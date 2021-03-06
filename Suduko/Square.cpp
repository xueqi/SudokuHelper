//
//  state.cpp
//  Suduko
//
//  Created by Xueqi Liu on 9/14/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#include "Square.hpp"
#include "Cluster.hpp"

// ---------------------------------------------------------------------------
// Square
Square::Square(char initChar, sint row, sint col)
: State(initChar), row(row), col(col) {
    // cerr << "Square " << row << ", " << col << " constructed"<< endl;
    
}

// ---------------------------------------------------------------------------
Square::Square() : State('-'), row(0), col(0) {
    // cerr << "Constructing empty square " << row << ", " << col << endl;
}

// ---------------------------------------------------------------------------
Square::~Square() {
    // cerr << "Deleting Square " << row << ", " << col << endl;
}

// ---------------------------------------------------------------------------
void Square::addCluster(Cluster * cluster) {
    clues.push_back(cluster);
}

// ---------------------------------------------------------------------------
int Square::numPossibilities() const {
    int n = 0, pos = possibilities >> 1;
    while(pos > 0) {
        if (pos & 1) n++;
        pos >>= 1;
    }
    return n;
}


// ---------------------------------------------------------------------------
// set squre to ch. if success, return true, else return false;
void Square::move(char ch) {
    State::move(ch);
    for (Cluster * cluster : clues) {
        cluster->shoop(value);
    }
}


// ---------------------------------------------------------------------------
ostream& Square::print(ostream& out) const {
    out << "Square [" << setw(2) << row << ", " << setw(2) << col << "] ";
    State::print(out);
    out << "  P: " << setw(2) << numPossibilities() << " ";
    return out;
}

// ---------------------------------------------------------------------------
// remove one possiblity from this state
void Square::turnOff(int n) {
    possibilities &= ~(1 << n);
}

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

void State::move(char ch) {
    if (ch != 0 && fixed) {
        // do we call fatal here? fatal will terminate the program
        // but we still need give user chance to continue
        say("Could not change the value");
    }
    if (ch != 0 &&!validInput(ch)) {
        cerr << "Wrong input for State value. Expects 1 to 9" << endl;
    }
    // check if value is possible?
    if (ch != 0)
        value = ch;
}

