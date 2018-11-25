#ifndef BINTREEEND_H
#define BINTREEEND_H

#include "bintreenode.h"

class BinTreeEnd : public BinTreeNode
{
public:
    BinTreeEnd();
    BinTreeEnd(vector<BinTreeNode>* vec, char ch, int count);

    char ch;
};

#endif // BINTREEEND_H
