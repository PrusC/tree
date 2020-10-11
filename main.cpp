#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(2);
    s.insert(5);
    s.insert(25);
    s.insert(1);

    for (auto el: s) {
        cout << el << endl;
    }
    cout << "----------" << endl;

    cout << *prev(s.end()) << endl;

    return 0;
}
