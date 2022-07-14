#include <bits/stdc++.h>

using namespace std;

// Comparison function for sorting the set by increasing order of its pair's second value
struct cmpStruct {
    template <typename T>

    // Comparator function for 'set<pair<int, string>, cmpStruct>'
    // pair.first:  int, the number of bird species occurences
    // pair.second: string,  bird species name
    bool operator()(const T& lhs, const T& rhs) const {
        if (lhs.first != rhs.first) {
            return lhs.first > rhs.first;
        }
        return lhs.second < rhs.second;
    }
};

void SortMap(const map<int, int>& dict) {
    // Declare set of pairs and insert pairs according to the comparator 'cmpStruct'
    set<pair<int, int>, cmpStruct> S(dict.begin(), dict.end());

    // Print the sorted values
    for (const auto& pair_from_set: S) {
        cout << pair_from_set.first << " : " << pair_from_set.second << endl;
    }
}

int main() {
    // Let's we have set of pairs: "set<pair<int, int>"
    // Our task is to sort set in descending order, firstly by pair.first and secondly by pair.second

    // Declare and initialize map
    map<int, int> M = {{8, 5},
                       {8, 6},
                       {8, 4},
                       {9, 1}};
    SortMap(M);

    return 0;
}
