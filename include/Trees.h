#ifndef TREES_H
#define TREES_H
#include <iostream>
using namespace std;
template <typename T>
class Node{
private:
    T key;
    bool red;
    Node* left;
    Node* right;
    Node* parent;

public:
    Node(T k);
    T getKey();
    bool isRed();
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    void setKey(T k);
    void setRed(bool rd);
    void setLeft(Node*l);
    void setRight(Node* r);
    void setParent(Node* p);
    bool isBlack();
    void makeRed();
    void makeBlack();
    virtual ~Node();
};

#include "Trees.tpp"

#endif // TREES_H
