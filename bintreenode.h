#ifndef BINTREENODE_H
#define BINTREENODE_H

#include <limits>
#include <utility>
#include <vector>

using namespace std;

class BinTreeNode
{
protected:
    BinTreeNode(vector<BinTreeNode>* vec, int count = 0);
public:
    BinTreeNode(vector<BinTreeNode>* vec, size_t left, size_t right, int count = 0);
    virtual ~BinTreeNode();



    unsigned int count;

private:
    size_t left,
           right;

protected:
    size_t parent;

    size_t selfId;

    vector<BinTreeNode> *vec;

public:
    void setLeft(size_t left);
    size_t getLeft() const;

    void setRight(size_t right);
    size_t getRight() const;

    void setParent(size_t parent);
    size_t getParent() const;
};

#endif // BINTREENODE_H
