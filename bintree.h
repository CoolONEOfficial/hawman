#ifndef BINTREE_H
#define BINTREE_H

#include "bintreeend.h"

#include <vector>

class BinTree
{
public:
    BinTree();

    const size_t NoId = numeric_limits<size_t>::max();

    vector<BinTreeEnd> ends;
    vector<BinTreeNode> nodes;

    void addNode(BinTreeNode node);
};

#endif // BINTREE_H
