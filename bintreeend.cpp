#include "bintreeend.h"

BinTreeEnd::BinTreeEnd() {}

BinTreeEnd::BinTreeEnd(vector<BinTreeNode> *vec, char ch, int count)
    : BinTreeNode(vec, count)
{
    this->ch = ch;
}
