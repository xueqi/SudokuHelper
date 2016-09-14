//
//  main.cpp
//  Suduko
//
//  Created by Xueqi Liu on 9/14/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#include "tools.hpp"
#include "square.hpp"
void testSquare();
int main(int argc, const char * argv[]) {
    banner();
    testSquare();
    bye();
    return 0;
}

void testSquare() {
    cout << "construct A valid Fixed Square" << endl;
    Square sq1('1');
    cout << "sq1: " << sq1 << endl;
    
}
