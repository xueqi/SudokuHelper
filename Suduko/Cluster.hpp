//
//  Cluster.hpp
//  Suduko
//
//  Created by Xueqi Liu on 10/3/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#ifndef Cluster_hpp
#define Cluster_hpp

#include "tools.hpp"
#include "Square.hpp"

enum ClusterT {
    BOX,
    ROW,
    COL
};

class Cluster {
private:
    ClusterT clusterType;
    vector<Square *> squares;
    int numSquares;
    void addSquare(Square *square);
public:
    Cluster(ClusterT clusterType, vector<Square *> squares);
    void shoop(char val);
    ostream& print(ostream&) const;
};

inline ostream& operator<<(ostream& os, const Cluster& c) {return c.print(os);}
#endif /* Cluster_hpp */
