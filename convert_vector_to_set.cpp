#include <iostream>
#include <vector>
#include <set>

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::set;


template <class T>
void printCollection(T collection) {
    for(auto it = collection.begin(); it != collection.end(); ++it) {
        if (it < (collection.end()-1)) {
            cout << (*it) << ", ";
        } else {
            cout << (*it) << endl;
        }
    } 
}

int main() {
    vector<int> v {1, 5, 7, 12, 1, 4, 2, 3, 4, 5};
    set<int> my_set(v.begin(), v.end());

    cout << "vector v: ";
    printCollection(v);
    cout << "Vector size: " << v.size() << " elements." << endl;

    cout << "set my_set: ";
    for (set<int>::iterator  it = my_set.begin(); it != my_set.end(); ++it) {
        cout << (*it) << " ";
    }
    cout << endl;
    cout << "Set size: " << my_set.size() << " elements." << endl;

    return 0;
}
