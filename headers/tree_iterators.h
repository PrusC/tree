#pragma once

#include "tree_nodes.h"

namespace tree {


template <class T>
struct TreeNodeIterator {
    using value_type = T;
    using reference = T&;
    using pointer = T*;

    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;

    TreeNodeIterator(): _node() {}
    TreeNodeIterator(Node<T>* node): _node(node) {}

    TreeNodeIterator<T>& operator++() {
        _node = successor(_node);
        return *this;
    }

    TreeNodeIterator<T>& operator--() {
        _node = predecessor(_node);
        return *this;
    }

    bool operator==(const TreeNodeIterator<T>& other) const {
        return _node == other._node;
    }

    bool operator!=(const TreeNodeIterator<T>& other) const {
        return _node != other._node;
    }

    reference operator*() const {
        return _node->_value;
    }

    pointer operator->() const {
        return &(_node->_value);
    }

private:
    Node<T> *_node;

};


template <class T>
struct TreeNodeConstIterator {
    using value_type = T;
    using reference = const T&;
    using pointer = const T*;

    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;

    TreeNodeConstIterator(): _node() {}
    TreeNodeConstIterator(Node<T>* node): _node(node) {}

    TreeNodeConstIterator<T>& operator++() {
        _node = successor(_node);
        return *this;
    }

    TreeNodeConstIterator<T>& operator--() {
        _node = predecessor(_node);
        return *this;
    }

    bool operator==(const TreeNodeConstIterator<T>& other) const {
        return _node == other._node;
    }

    bool operator!=(const TreeNodeConstIterator<T>& other) const {
        return _node != other._node;
    }

    reference operator*() const {
        return _node->_value;
    }

    pointer operator->() const {
        return &(_node->_value);
    }

private:
    Node<T> *_node;

};


}
