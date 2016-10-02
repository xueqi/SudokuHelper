//
//  Board.cpp
//  Suduko
//
//  Created by Xueqi Liu on 9/26/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#include "Board.hpp"

// -----------------------------------------------------------------------------
Board::Board(const char * filename) {
    ifstream inStream(filename);
    if (!inStream) {
        fatal("Could not open file: %s\nPlease check if file exists", filename);
    }
    bool successRead = true;
    inStream >> noskipws;
    for (int row = 1; row <= NROWS; ++row) {
        for (int col = 1; col <= NCOLS; ++col) {
            char c;
            inStream >> c;
            if (!inStream) {
                cerr << "Error reading row " << row << " col " << col << endl;
                successRead = false;
                break;
            }
            sub(row, col) = Square(c, row, col);
        }
        if (successRead) {
            char newline = '\0';
            inStream >> newline;
            if (!inStream || newline != '\n') {
                successRead = false;
            }
        }
        if (!successRead) break;
    }
    if (successRead) {
        char tmp;
        inStream >> skipws >> tmp;
        if (!inStream.eof()) successRead = false;
    } else {
        fatal("File format wrong, check file content in %s", filename);
    }
}
// -----------------------------------------------------------------------------
// TODO: Set the destructor to default after done
Board::~Board() {
    cerr << "Calling Board Destructor" << endl;
}

// -----------------------------------------------------------------------------
// Square access. No boundary check currently.
// Caller should do the boundary check.
Square& Board::sub(int row, int col) {
    return bd[(row - 1) * NCOLS + col - 1];
}
// -----------------------------------------------------------------------------
ostream& Board::print(ostream& out) {
    for (int row = 1; row <= NROWS; ++row) {
        for (int col = 1; col <= NCOLS; ++col) {
            out << sub(row, col) << endl;
        }
        out << endl;
    }
    return out;
}