//
//  square.cpp
//  Suduko
//
//  Created by Xueqi Liu on 9/14/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#include "square.hpp"

Square::Square(char initChar) : value(initChar) {
    if (!checkInput(value)) {
        fatal("Wrong input for Square Constructor: %c\nExpects 1 to 9", value);
    }
    if (value == '-') {
        possibilities = POSSIBLE_ALL;
        fixed = false;
    } else if (value != '0' && isdigit(value)) {
        possibilities = POSSIBLE_NONE;
        fixed = true;
    }
}

void Square::move(char ch) {
    if (fixed) {
        fatal("Could not change the value");
    }
    if (!checkInput(ch)) {
        cerr << "Wrong input for Square value. Expects 1 to 9" << endl;
        return;
    }
    // check if value is possible?
    if (valueIsPossible(ch))
        value = ch;
    else {
        // do we give hint to user?
        cerr << "Could not put " << ch << " here." << endl;
    }
    // emit value changed signal?
    
}

void Square::print(ostream &out) const {
    for (int k = 1; k < 10; ++k) {
        out << ((possibilities >> k) & 1 ? 'k' : '-');
    }
}

bool Square::checkInput(char ch) {
    return ch == '-' || (isdigit(ch) && ch != '0');
}

bool Square::valueIsPossible(char ch) {
    return (possibilities >> (ch - '0')) & 1;
}

ostream& operator<<(ostream& out, const Square& square) {
    square.print(out);
    return out;
}