#ifndef TREES_H
#define TREES_H
#include <iostream>

class Node{
private:
    int key;
    bool red;
    Node* left;
    Node* right;
    Node* parent;

public:
    Node(int k);
    int getKey();
    bool isRed();
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    void setKey(int k);
    void setRed(bool rd);
    void setLeft(Node*l);
    void setRight(Node* r);
    void setParent(Node* p);
    bool isBlack();
    void makeRed();
    void makeBlack();
    virtual ~Node();
};

#endif // TREES_H
