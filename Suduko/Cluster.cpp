//
//  Cluster.cpp
//  Suduko
//
//  Created by Xueqi Liu on 10/3/16.
//  Copyright © 2016 Xueqi Liu. All rights reserved.
//

#include "Cluster.hpp"
const char *Cluster::clusterName[] = {"BOX", "ROW", "COL"};

// ----------------------------------------------------------------------------
Cluster::Cluster(ClusterT ctype, vector<Square*> squares) {
    clusterType = ctype;
    for (Square *square : squares) {
        addSquare(square);
        square->addCluster(this);
    }
}

// ----------------------------------------------------------------------------
void Cluster::shoop(char val) {
    for (Square * square : squares) {
        square->turnOff(val - '0');
    }
}

// ----------------------------------------------------------------------------
ostream& Cluster::print(ostream & out) const {
    out << clusterName[clusterType] << " Cluster" << endl;
    for (Square* square : squares) {
        square->print(out);
        out << endl;
    }
    out << endl;
    return out;
}