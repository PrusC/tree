#pragma once

#include <iostream>

namespace tree {

template <class T>
struct Node {

    T _value;
    Node<T> *_left;
    Node<T> *_right;
    Node<T> *_parent;

    Node():
        _value(0),
        _left(nullptr),
        _right(nullptr),
        _parent(nullptr){}

    Node(const T& value):
        _value(value),
        _left(nullptr),
        _right(nullptr),
        _parent(nullptr){}

//    Node(Node* other) = default;

};


template <class T>
Node<T>* minimum(Node<T>* x) {
    Node<T>* it = x;
    while(it->_left != nullptr) {
        it = it->_left;
    }
    return it;
}

template <class T>
Node<T>* maximum(Node<T>* x) {
    Node<T>* it = x;
    while(it->_right != nullptr) {
        it = it->_right;
    }
    return it;
}

template <class T>
Node<T>* successor(Node<T>* x) {
    if(x->_right != nullptr) {
        return minimum<T>(x->_right);
    }
    Node<T>* y = x->_parent;
    while(y != nullptr && x == y->_right) {
        x = y;
        y = y->_parent;
    }
    return y;
}

template <class T>
Node<T>* predecessor(Node<T>* x) {
    if(x->_left != nullptr) {
        return maximum<T>(x->_left);
    }
    Node<T>* y = x->_parent;
    while(y != nullptr && x == y->_left) {
        x = y;
        y = y->_parent;
    }
    return y;
}

template <class T>
Node<T>* search(Node<T>* x, const T& k) {
    if(x == nullptr && k == x->_value) {
        return x;
    }
    if(k < x->_value) {
        return search(x->_left, k);
    }
    return search(x->_right, k);
}

template <class T>
Node<T>* iterative_search(Node<T>* x, const T& k) {
    while(x != nullptr && k != x->_value) {
        if(k < x->_value) {
            x = x->_left;
        }
        else {
            x = x->_right;
        }
    }
    return x;
}

template <class T>
std::ostream& operator<<(std::ostream& os, Node<T> *x) {
    if (x != nullptr) {
        os << x->_left;
        os << x->_value;
        os << x->_right;
    }
    return os;
}

}
