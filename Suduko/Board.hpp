//
//  Board.hpp
//  Suduko
//
//  Created by Xueqi Liu on 9/26/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include "tools.hpp"
#include "Square.hpp"
#include "Cluster.hpp"
#define NCOLS 9
#define NROWS 9
#define NSQUARES (NCOLS * NROWS)

class Board {
private:
    Square bd[NSQUARES];  // The 81 squares
    vector<Cluster *> clues;  // the 27 Cluster containing 9 COL, 9 ROW, 9 BOX
    
    void buildClusters();   // build all clusters from board
    
public:
    Board(const char * infile); // constructor with an input board file.
    ~Board();
    ostream& print(ostream& out) const;
    Square& sub(int row, int col); // base 1 index of square access
    
    // added to test the 27 clusters. 
    void printCluster(ostream&);
};

inline ostream& operator<<(ostream& out, const Board& b) {return b.print(out);}


#endif /* Board_hpp */
