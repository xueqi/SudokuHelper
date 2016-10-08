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

class Cluster;
typedef short int sint;
class State {
protected:
    sint possibilities;
    char value;
    bool fixed; 
private:
    // check if input is valid for current possible
    
public:
    State() = default;
    State(char initChar);
    ~State() = default;
    void remove();
    void move(char ch);
    ostream& print(ostream &out) const;
    
    // static members
    static bool validInput(char ch)
        {return ch == '-' || (isdigit(ch) && ch != '0');}
}; /* end class State */


class Square : public State {
private:
    sint row;
    sint col;
    vector<Cluster*> clues;
    bool valueIsPossible(char ch) {return (possibilities >> (ch - '0')) & 1;}
    int numPossibilities() const;
public:
    Square(char initChar, sint row, sint col);
    Square();
    ~Square();
    ostream& print(ostream&) const;
    void addCluster(Cluster*);
    void turnOff(int n);
    void move(char ch = 0);

    
};

inline ostream& operator<<(ostream& out, const State& s) {return s.print(out);}
inline ostream& operator<<(ostream& out, const Square& s) {return s.print(out);}

#endif /* state_hpp */
