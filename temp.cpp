#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

using namespace std;

// Comparison function for sorting the set by DECREASING order of its pair's second value
struct compStruct {
    template <typename T>

    // Comparator function
    bool operator()(const T& lhs, const T& rhs) const {
        if (lhs.second != rhs.second) {
            return lhs.second > rhs.second;
        }
        return lhs.first < rhs.first;
    }
};

// Function to sort the map according to value in a (key-value) pairs
void SortMap(map<string, int>& M) {
    // Declare set of pairs and insert pairs according to the comparator function compStruct()
    set<pair<string, int>, compStruct> S(M.begin(), M.end());
    // set<pair<string, int>> S(M.begin(), M.end());

    // Print the sorted value
    for (auto& it : S) {
        cout << it.first << ' '
             << it.second << endl;
    }
}

// Driver Code
int main() {
    // Declare Map
    map<string, int> M;

    // Given Map
    M = {{"Avatar", 1},
         {"GfG", 3},
         {"To", 2},
         {"Avaaar", 1},
         {"Welcome", 2}};

    // Function Call
    SortMap(M);
    return 0;
}
