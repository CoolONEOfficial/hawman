#include "bintree.h"
#include "bintreenode.h"

#include <limits>

BinTreeNode::BinTreeNode(vector<BinTreeNode> *vec, size_t count)
{
    this->vec = vec;
    this->count = count;
}

BinTreeNode::BinTreeNode() {}

BinTreeNode::BinTreeNode(vector<BinTreeNode> *vec, size_t left, size_t right, size_t count)
    :BinTreeNode(vec, count)
{
    this->left = left;
    this->right = right;
    vec->at(left).parent = selfId;
    vec->at(right).parent = selfId;
}

BinTreeNode::~BinTreeNode()
{
    if(vec->size() > left) {
        vec->at(left).parent = BinTree::NoId;
    }

    if(vec->size() > right) {
        vec->at(right).parent = BinTree::NoId;
    }
}

void BinTreeNode::setLeft(size_t left)
{
    if(vec->size() > left) {
        vec->at(left).parent = BinTree::NoId;
    }
    this->left = left;
}

size_t BinTreeNode::getLeft() const
{
    return left;
}

void BinTreeNode::setRight(size_t right)
{
    if(vec->size() > right) {
        vec->at(right).parent = BinTree::NoId;
    }
    this->right = right;
}

size_t BinTreeNode::getRight() const
{
    return right;
}

void BinTreeNode::setParent(size_t parent)
{
    this->parent = parent;
}

size_t BinTreeNode::getParent() const
{
    return parent;
}
