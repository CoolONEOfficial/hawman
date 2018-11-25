#ifndef BINTREE_H
#define BINTREE_H

#include "bintreenode.h"
#include "bintreeend.h"

#include <limits>
#include <vector>

class BinTree
{
public:
    BinTree();

    static const size_t NoId = numeric_limits<size_t>::max();

    vector<BinTreeEnd> ends;
    vector<BinTreeNode> nodes;

    void addNode(BinTreeNode node);
    void addEnd(BinTreeEnd end);
};

#endif // BINTREE_H
