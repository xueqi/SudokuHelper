//
//  square.hpp
//  Suduko
//
//  Created by Xueqi Liu on 9/14/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#ifndef square_hpp
#define square_hpp

#include "tools.hpp"

#define POSSIBLE_ALL 0x3fe
#define POSSIBLE_NONE 0x0

class Square {
private:
    char value;
    short possibilities;
    bool fixed; // initialized by game
    
    // helper function
    bool checkInput(char ch);
    bool valueIsPossible(char ch);
public:
    Square(char initChar);
    ~Square() = default;
    void move(char ch);
    void remove();
    void print(ostream &out) const;
};

ostream& operator<<(ostream& out, const Square& square);

#endif /* square_hpp */
