//
//  main.cpp
//  Suduko
//
//  Created by Xueqi Liu on 9/14/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#include "tools.hpp"
#include "state.hpp"

void testState();

// -----------------------------------------------------------------------------
int main(int argc, const char * argv[]) {
    banner();
    testState();
    bye();
    return 0;
}

// -----------------------------------------------------------------------------
void testState() {
    // order of member in State class would change the size of State instance;
    cout << "State structure size: " << sizeof(State) << endl;
    cout << "===============================================================\n";
    cout << "construct A valid Fixed State" << endl;
    State sq1('1');
    cout << "sq1: " << sq1 << endl;
    
    cout << "===============================================================\n";
    cout << "construct A valid empty State" << endl;
    State sq2('-');
    cout << "sq2: " << sq2 << endl;
    
    cout << "===============================================================\n";
    cout << "construct A invalid State (should fail)" << endl;
    /* this will cause fatal to exit the program.
    State sq3('0');
    cout << "sq3: " << sq3 << endl;
    */
    
    cout << "===============================================================\n";
    // test move
    cout << "move sq2 to 2" << endl;
    sq2.move('2');
    cout << "sq2: " << sq2 << endl;

    
    cout << "===============================================================\n";
    cout << "move sq1 to 2 (should fail)" << endl;
    /*
    // sq1 could not move
    sq1.move('2'); // bang!
    cout << "sq1: " << sq1 << endl;
    */
    
    // test move to invalid char
    cout << "===============================================================\n";
    cout << "move sq2 to invlid value \"a\". sq2 should not change" << endl;
    sq2.move('a');
    cout << "sq2: " << sq2 << endl;
    
    cout << "===============================================================\n";
    cout << "remove sq2" << endl;
    sq2.remove();
    cout << "sq2: " << sq2 << endl;
    
    cout << "===============================================================\n";
    cout << "remove sq1, should fail" << endl;
    /*
    sq1.remove();
    cout << "sq1: " << sq1 << endl;
    */
    cout << "===============================================================\n";
    cout << "Test state ended.\n";
    
}