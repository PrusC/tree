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
        _header._left = nullptr;
        _header._right = &_header;
    }

    Node<T>*& root() {
        return _header._left;
    }

    const Node<T>* root() const {
        return _header._left;
    }

    void setRoot(Node<T>*& node) {
        _header._left = node;
        node->_parent = &_header;
    }

    void setRoot(const Node<T>& node) {
        _header._parent = &node;
    }

    Node<T>*& first() {
        return _header._right;
    }

    const Node<T>* first() const {
        return _header._right;
    }

    void setFirst(Node<T>*& node) {
        _header._right = node;
    }

    void setFirst(const Node<T>& node) {
        _header._right = node;
    }

    Node<T>* header() {
        return &_header;
    }

    const Node<T>* header() const {
        return &_header;
    }

};


template <class T>
class BinaryTree {

public:

    using iterator = TreeNodeIterator<T>;
    using const_iterator = TreeNodeConstIterator<T>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    BinaryTree(): head(), _size() {}

    bool isEmpty() const {
        return head.root() == nullptr;
    }

    size_t size() const {
        return _size;
    }

    iterator find(const T& k) {
        Node<T>* it = search(head.root(), k);
        if(it == nullptr) {
            return iterator(head.header());
        }
        return iterator(it);
    }

    const_iterator find(const T& k) const {
        Node<T>* it = search(head.root(), k);
        if(it == nullptr) {
            return const_iterator(head.header());
        }
        return const_iterator(it);
    }

    iterator begin() {
        return iterator(head.first());
    }

    const_iterator begin() const {
        return const_iterator(head.first());
    }

    iterator end() {
        return iterator(head.header());
    }

    const_iterator end() const {
        return const_iterator(head.header());
    }

    reverse_iterator rbegin() {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    iterator insert(const T& k) {
        Node<T>* parent = findInsertParent(head.root(), k);

        if(parent != nullptr && parent->_value == k) {
            return iterator(parent);
        }

        Node<T> *z = new Node<T>(k);
        z->_parent = parent;
        if(parent ==  nullptr) {
            head.setRoot(z);
            head.setFirst(z);
//            z->_parent = head.header();
        }
        else {
            if(k < parent->_value) {
                parent->_left = z;
                if (parent == head.first()) {
                    head.setFirst(z);
                }
            }
            else {
                parent->_right = z;
            }
        }
        _size ++;
        return iterator(z);

    }


    iterator erase(const T& k) {
        Node<T>* y = nullptr;
        Node<T>* x = nullptr;
        Node<T>* z = search(head.root(), k);

        if(z == nullptr) {
            return end();
        }

        if(z->_left == nullptr || z->_right == nullptr) {
            y = z;
        }
        else {
            y = successor(z);
        }

        if(y->_left != nullptr) {
            x = y->_left;
        }
        else {
            x = y->_right;
        }

        if(x != nullptr) {
            x->_parent = y->_parent;
        }
        if(y->_parent == nullptr) {
            head.setRoot(x);
        }
        else if(y == y->_parent->_left) {
            y->_parent->_left = x;
        }
        else {
            y->_parent->_right = x;
        }
        if(y != z) {
            z->_value = y->_value;
        }
        _size --;
        return iterator(y);
    }


private:

    TreeHeader<T> head;
    size_t _size;

    Node<T>* findInsertParent(Node<T> *root, const T& k) {
        Node<T>* y = nullptr;
        Node<T>* x = root;

        while(x != nullptr) {
            if (k == x->_value) {
                return x;
            }
            y = x;
            if (k < x->_value) {
                x = x->_left;
            }
            else {
                x = x->_right;
            }
        }
        return y;
    }

};


}
