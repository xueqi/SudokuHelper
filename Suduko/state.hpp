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

#define POSSIBLE_ALL 0x3fe
#define POSSIBLE_NONE 0x0

class State {
private:
    short possibilities;
    char value;
    bool fixed; // initialized by game
    
    // helper function
    bool checkInput(char ch);
    bool valueIsPossible(char ch);
public:
    State(char initChar);
    ~State() = default;
    bool move(char ch);
    void remove();
    void print(ostream &out) const;
};

ostream& operator<<(ostream& out, const State& state);

#endif /* state_hpp */
