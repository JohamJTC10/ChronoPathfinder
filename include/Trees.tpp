#include "Trees.h"

template <typename T>
Node<T>::Node(T k) {
    key = k;
    red = true;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

template <typename T>
T Node<T>::getKey() {
    return key;
}

template <typename T>
bool Node<T>::isRed() {
    return red;
}

template <typename T>
Node<T>* Node<T>::getLeft() {
    return left;
}

template <typename T>
Node<T>* Node<T>::getRight() {
    return right;
}

template <typename T>
Node<T>* Node<T>::getParent() {
    return parent;
}

template <typename T>
void Node<T>::setKey(T k) {
    key = k;
}

template <typename T>
void Node<T>::setRed(bool rd) {
    red = rd;
}

template <typename T>
void Node<T>::setLeft(Node<T>* l) {
    left = l;
    if (l) l->parent = this;
}

template <typename T>
void Node<T>::setRight(Node<T>* r) {
    right = r;
    if (r) r->parent = this;
}

template <typename T>
void Node<T>::setParent(Node<T>* p) {
    parent = p;
}

template <typename T>
bool Node<T>::isBlack() {
    return !red;
}

template <typename T>
void Node<T>::makeRed() {
    red = true;
}

template <typename T>
void Node<T>::makeBlack() {
    red = false;
}

template <typename T>
Node<T>::~Node() {
    // nada
}
