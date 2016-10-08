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
    inStream.close();
    
    buildClusters();
    
    // initial shoops;
    for (Square& square : bd) {
        square.move();
    }
    
}
// -----------------------------------------------------------------------------
//
void Board::buildClusters() {
    vector<Square*> squares(9);
    // build row clusters
    for (int row = 1; row <= NROWS; ++row) {
        for(int col = 1; col <= NCOLS; ++col) {
            squares[col - 1] = &sub(row, col);
        }
        clues.push_back(new Cluster(ROW, squares));
    }
    // build col clusters
    for (int col = 1; col <= NCOLS; ++col) {
        for (int row = 1; row <=NROWS; ++row) {
            squares[row - 1] = &sub(row, col);
        }
        clues.push_back(new Cluster(COL, squares));
    }
    // build box clusters
    for (int m = 0; m < 3; ++m) { // row of box
        for (int n = 0; n < 3; ++n) { // col of box
            int count = 0;
            for (int p = 0; p < 3; ++p) { // row in box
                for (int q = 0; q < 3; ++q) { // col in box
                    int row = m * 3 + p + 1, col = n * 3 + q + 1;
                    squares[count++] = &sub(row, col);
                }
            }
            clues.push_back(new Cluster(BOX, squares));
        }
    }
}

// -----------------------------------------------------------------------------
// TODO: Set the destructor to default after done
Board::~Board() {
    for (Cluster * clue : clues) {
        delete clue;
    }
    cerr << "Calling Board Destructor" << endl;
}

// -----------------------------------------------------------------------------
// Square access. No boundary check currently.
// Caller should do the boundary check.
Square& Board::sub(int row, int col) {
    return bd[(row - 1) * NCOLS + col - 1];
}
// -----------------------------------------------------------------------------
ostream& Board::print(ostream& out) const {
    for (int row = 1; row <= NROWS; ++row) {
        for (int col = 1; col <= NCOLS; ++col) {
            out << bd[(row - 1) * NCOLS + col - 1] << endl;
        }
        out << endl;
    }
    return out;
}

// -----------------------------------------------------------------------------
void Board::printCluster(ostream& out) {
    for (Cluster* cl : clues) {
        out << *cl << endl;
    }
}