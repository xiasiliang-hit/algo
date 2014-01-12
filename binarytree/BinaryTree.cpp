#include "BinaryTree.h"
#include <iostream>
using namespace std;

int leafNode, oneChildNode, twoChildNode = 0;

void CreateBtree(BinTreePtr& nodePtr)
{
    char ch;
    cin >> ch ;
    if (ch == '#')
    {
        nodePtr = NULL;
    }
    else
    {
        nodePtr = new BinTree;
        nodePtr -> data = ch ;
        CreateBtree(nodePtr -> lchild);
        CreateBtree(nodePtr -> rchild);
    }
}

void PreOrder(BinTreePtr nodePtr, void (*visit)(BinTreePtr& nodePtr))
{
    if (nodePtr != NULL)
    {
        visit(nodePtr);
        PreOrder(nodePtr -> lchild, visit);
        PreOrder(nodePtr -> rchild, visit);
    }
}

void print(BinTreePtr& nodePtr)
{
    cout << nodePtr -> data;
}

void count(BinTreePtr& nodePtr)
{
    if (nodePtr -> lchild == NULL && nodePtr -> lchild == NULL)
    {
        leafNode++;
    }
    else if (nodePtr -> lchild != NULL && nodePtr -> lchild != NULL)
    {
        twoChildNode++;
    }
    else
    {
        oneChildNode++;
    }
}

void changeChild(BinTreePtr& nodePtr)
{
    BinTreePtr temp = nodePtr -> lchild;
    nodePtr -> lchild = nodePtr -> rchild;
    nodePtr -> rchild = temp;
}

void displayCount()
{
    cout << "\n\ncount the nodes:" << endl
        << "leafNode: " << leafNode << endl
        << "oneChildNode: " << oneChildNode << endl
        << "twoChildNode: " << twoChildNode << endl;
}
