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
int main(int argc, const char * argv[]) {
    banner();
    testState();
    bye();
    return 0;
}

void testState() {
    cout << "State structure size: " << sizeof(State) << endl;
    cout << "construct A valid Fixed State" << endl;
    State sq1('1');
    cout << "sq1: " << sq1 << endl;
    cout << "construct A valid empty State" << endl;
    State sq2('-');
    cout << "sq2: " << sq2 << endl;
    cout << "construct A invalid State" << endl;
    /* this will cause fatal to exit the program. How to test?
    State sq3('0');
    cout << "sq3: " << sq3 << endl;
    */
    
    // test move
    cout << "move sq2 to 2" << endl;
    sq2.move('2');
    cout << "sq2: " << sq2 << endl; // output is the same as before.
    // we need a method to distinguish before and after move
    
    /*
    // sq1 could not move
    cout << "move sq1 to 2" << endl;
    sq1.move('2'); // bang! fatal again? How to test this?
    cout << "sq1: " << sq1 << endl;
    */
    
    // test move to invalid char
    sq2.move('a');
    cout << "sq2: " << sq2 << endl;
    
}
