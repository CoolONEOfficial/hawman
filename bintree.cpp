#include "bintree.h"

BinTree::BinTree()
{

}

void BinTree::addNode(BinTreeNode node)
{
    nodes.push_back(node);
}

void BinTree::addEnd(BinTreeEnd end)
{
    ends.push_back(end);
}
