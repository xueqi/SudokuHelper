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
    Square bd[NSQUARES];
    vector<Cluster> clusters;
    
    static const char * clusterName[];
    void buildClusters();
    
public:
    Board(const char * infile);
    ~Board();
    ostream& print(ostream& out);
    Square& sub(int row, int col);
};

// sub in Board is not const function, TODO: fix this to const
inline ostream& operator<<(ostream& out, Board& b) {return b.print(out);}


#endif /* Board_hpp */
