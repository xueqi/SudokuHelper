//
//  main.cpp
//  Suduko
//
//  Created by Xueqi Liu on 9/14/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#include "tools.hpp"
#include "Square.hpp"
#include "Board.hpp"
#include "Cluster.hpp"

// -----------------------------------------------------------------------------
void testState();
void testSquare();
void testBoard();
void testCluster();

// -----------------------------------------------------------------------------
int main(int argc, const char * argv[]) {
    banner();
    testCluster();
    testBoard();
    testSquare();
    testState();
    bye();
    return 0;
}

// -----------------------------------------------------------------------------
void testCluster() {
    cout << "===============================================================\n";
    cout << "Begin testing cluster\n";
    // create 9 squares;
    vector<Square *> squares;
    for (char ch = 1; ch <= 9; ch++) {
        squares.push_back(new Square('-', 1, ch));
    }
    Cluster cluster(ROW, squares);
    cout << cluster << endl;
    squares[0]->move('1');
    squares[5]->move('3');
    cout << "All squares should turn off 1 and 3\n";
    cout << cluster << endl;
    for (Square * square : squares) {
        delete square;
    }
    cout << "End testing cluster\n";
    cout << "===============================================================\n";
}

// -----------------------------------------------------------------------------
void testBoard() {
    cout << "Beginning testing board:" << endl;
    cout << "===============================================================\n";
    Board board("sudo-test1.txt");
    cout << board << endl;
    board.printCluster(cout);
    cout << "Done testing board\n";
}

// -----------------------------------------------------------------------------
void testSquare() {
    cout << "===============================================================\n";
    cout << "\nconstruct square with default constructor\n";
    Square sq1;
    cout << sq1 << endl;
    cout << "===============================================================\n";
    cout << "\nconstruct square with three parameter\n";
    Square sq2('4', 3, 2);
    cout << sq2 << endl;
    cout << "===============================================================\n";
    cout << "\nconstruct square with three parameters and no value\n";
    Square sq3('-', 4, 5);
    cout << sq3 << endl;
    cout << "===============================================================\n";
    cout << "\nturnOff possibility of 1\n";
    sq3.turnOff(1);
    cout << sq3 << endl;
    cout << "===============================================================\n";
    // test move
    cout << "move sq2 to 2" << endl;
    sq2.move('2');
    cout << "sq2: " << sq2 << endl;
    
    
    cout << "===============================================================\n";
    cout << "move sq1 to 2 (should say Could not change the value )" << endl;
    
    // sq1 could not move
    sq1.move('2'); // bang!
    cout << "sq1: " << sq1 << endl;
    
    
    // test move to invalid char
    cout << "===============================================================\n";
    cout << "move sq2 to invlid value \"a\". sq2 should not change" << endl;
    sq2.move('a');
    cout << "sq2: " << sq2 << endl;
    
    cout << "===============================================================\n";
    cout << "Done testing square\n\n";
}

// -----------------------------------------------------------------------------
void testState() {
    // order of member in State class would change the size of State instance;
    cout << "===============================================================\n";
    cout << "construct A valid Fixed State" << endl;
    State state1('1');
    cout << "state1: " << state1 << endl;
    
    cout << "===============================================================\n";
    cout << "construct A valid empty State" << endl;
    State state2('-');
    cout << "state2: " << state2 << endl;
    
    cout << "===============================================================\n";
    cout << "construct A invalid State (should say Wrong input)" << endl;
    State state3('0');
    cout << "state3: " << state3 << endl;
    

    cout << "remove state2" << endl;
    state2.remove();
    cout << "state2: " << state2 << endl;
    
    cout << "===============================================================\n";
    cout << "remove sq1, should Could not change the value" << endl;
    state1.remove();
    cout << "state1: " << state1 << endl;
    
    cout << "===============================================================\n";
    cout << "Test state ended.\n";
    
}
