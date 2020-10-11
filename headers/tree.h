#pragma once

#include "tree_nodes.h"
#include "tree_iterators.h"

namespace tree {


template <class T>
class BinaryTree {

public:

    using iterator = TreeNodeIterator<T>;
    using const_iterator = TreeNodeConstIterator<T>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    BinaryTree(): root() {}

    bool isEmpty() const {
        return root == nullptr;
    }

    iterator find(const T& k) {
        return iterator(search(root, k));
    }

    const_iterator find(const T& k) const {
        return const_iterator(search(root, k));
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

};


}
