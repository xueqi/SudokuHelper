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
    ClusterT clusterType; // the cluster type
    vector<Square *> squares; // contains the 9 squares
    static const char * clusterName[]; // The cluster type Name for print
    void addSquare(Square *square) {squares.push_back(square);}
public:
    // Constructor with cluster type and 9 squares in a vector
    Cluster(ClusterT clusterType, vector<Square *> squares);
    void shoop(char val);
    ostream& print(ostream&) const;
};

inline ostream& operator<<(ostream& os, const Cluster& c) {return c.print(os);}
#endif /* Cluster_hpp */
