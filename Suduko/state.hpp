//
//  state.hpp
//  Suduko
//
//  Created by Xueqi Liu on 9/14/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#ifndef state_hpp
#define state_hpp

#include "tools.hpp"

#define POSSIBLE_ALL  0x3fe
#define POSSIBLE_NONE 0x0

class State {
private:
    short possibilities;
    char value;
    bool fixed; 
    
    // helper function
    // check if input is valid
    bool checkInput(char ch) {return ch == '-' || (isdigit(ch) && ch != '0');}
    // check if input is valid for current possible
    bool valueIsPossible(char ch) {return (possibilities >> (ch - '0')) & 1;}
    
public:
    State(char initChar);
    ~State() = default;
    bool move(char ch);
    void remove();
    ostream& print(ostream &out) const;
}; /* end class State */

inline ostream& operator<<(ostream& out, const State& s) {return s.print(out);}

#endif /* state_hpp */
