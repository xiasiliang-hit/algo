//this project is to bilud a binary tree ADT
//2009/05/31-2009/06/06
#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    BinTreePtr rootPtr = NULL;
    cout << "input the tree in pre-order, press '#' to stand for an empty node" << endl;
    CreateBtree(rootPtr);

    cout << "\nthe tree in pre-order: " << endl;
    PreOrder(rootPtr, print);

    PreOrder(rootPtr, count);
    displayCount();

    PreOrder(rootPtr, changeChild);
    cout << "\nafter change children, he tree in pre-order: " << endl;
    PreOrder(rootPtr, print);

    return 0;
}


/*void CreateBtree(BinTreePtr& nodePtr)
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
    //int leafNode, oneChildNode, twoChildNode = 0;

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
}*/


