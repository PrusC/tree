#pragma once

#include "tree_nodes.h"
#include "tree_iterators.h"

namespace tree {

template <class T>
struct TreeHeader {
    Node<T> _header;

    TreeHeader(): _header() {
        reset();
    }

    void reset() {
        _header._parent = nullptr;
        _header._left = &_header;
        _header._right = &_header;
    }

    Node<T>*& root() {
        return _header._parent;
    }

    const Node<T>* root() const {
        return _header._parent;
    }

    void setRoot(const Node<T>& node) {
        _header._parent = &node;
    }

    Node<T>*& left() {
        return _header._left;
    }

    const Node<T>* left() const {
        return _header._left;
    }

    Node<T>*& right() {
        return _header._right;
    }

    const Node<T>* right() const {
        return _header._right;
    }

    Node<T>& header() {
        return _header;
    }

    const Node<T> header() const {
        return _header;
    }

};


template <class T>
class BinaryTree {

public:

    using iterator = TreeNodeIterator<T>;
    using const_iterator = TreeNodeConstIterator<T>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    BinaryTree(): root(), head() {}

    bool isEmpty() const {
        return root == nullptr;
    }

    iterator find(const T& k) {
        Node<T>* it = search(root, k);
        if(it == nullptr) {
            return iterator(&head.header());
        }
        return iterator(search(root, k));
    }

    const_iterator find(const T& k) const {
        Node<T>* it = search(root, k);
        if(it == nullptr) {
            return const_iterator(&head.header());
        }
        return const_iterator(it);
    }

    iterator insert(const T& k) {
        Node<T> *y = nullptr;
        Node<T> *x = root;

        while(x != nullptr) {
            y = x;
            if (k < x->_value) {
                x = x->_left;
            }
            else {
                x = x->_right;
            }
        }
        Node<T> *z = new Node<T>(k);
        z->_parent = y;
        if (y == nullptr) {
            root = z;
//            head._header._le
        }
        else {
            if (k < y->_value) {
                y->_left = z;
            }
            else {
                y->_right = z;
            }
        }
        return iterator(z);
    }

    void erase(const T& k) {
//        if()
    }

private:

    Node<T>* root;
    TreeHeader<T> head;

};


}
