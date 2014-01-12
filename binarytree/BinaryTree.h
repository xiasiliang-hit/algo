#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

struct node
{
    char data;
    node* lchild;
    node* rchild;
};
typedef node BinTree, *BinTreePtr;


void CreateBtree(BinTreePtr& nodePtr);
void PreOrder(BinTreePtr nodePtr, void (*visit)(BinTreePtr& nodePtr));//visit the node by passing different function poiters
void displayCount();

void print(BinTreePtr& nodePtr);
void count(BinTreePtr& nodePtr);
void changeChild(BinTreePtr& nodePtr);

#endif // BINARYTREE_H_INCLUDED
