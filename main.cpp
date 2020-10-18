#include <iostream>
#include <algorithm>

#include "headers/tree.h"

using namespace std;

int main()
{
//    set<int> s;
//    s.insert(2);
//    s.insert(5);
//    s.insert(25);
//    s.insert(1);

//    for (auto el: s) {
//        cout << el << endl;
//    }
//    cout << "----------" << endl;

//    cout << *prev(s.end()) << endl;

    tree::BinaryTree<int> s;

    s.insert(2);
    s.insert(5);
    s.insert(25);
    s.insert(1);
    s.insert(-4);
    s.insert(3);
    auto it = find(begin(s), end(s), 25);
    cout << *it << endl;

    cout << "--------" << endl;
    for(auto el: s) {
        cout << el << endl;
    }
    auto at = s.erase(1);
    cout << "next " << *at << endl;
    cout << "--------" << endl;
    for(auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
