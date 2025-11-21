#ifndef RBT_H
#define RBT_H
#include <iostream>
#include "Trees.h"

class RBT
{
    private:
        Node* root;

        void rotateLeft(Node* x);
        void rotateRight(Node* x);
        Node* bstInsert(int key);
        void fixInsert(Node* x);
        void inorder(Node* x);
    public:
        RBT();

        void _insert(int key);
        bool _find(int key);
        void printRBT();
        virtual ~RBT();


};

#endif // RBT_H
