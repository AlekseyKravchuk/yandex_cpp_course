#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

map<string, int> MakeTypeCounter(const vector<string>& birds) {
    map<string, int> typeCounter;

    for (auto const& type : birds) {
        ++typeCounter[type];
    }

    return typeCounter;
}

// Comparison function for sorting the set by:
// 1) DECREASING order of its pair's second value (int, the number of type occurrences) and
// 2) INCREASING order (alphabetically) of its pair's first value  (string, the name of bird species)
struct cmpStruct {
    template <typename T>

    // Comparator function
    bool operator()(const T& lhs, const T& rhs) const {
        if (lhs.second != rhs.second) {
            return lhs.second > rhs.second;
        }
        return lhs.first < rhs.first;
    }
};

string FindWidespreadBird(const vector<string>& types) {
    map<string, int> typeCounter = MakeTypeCounter(types);
    set<pair<string, int>, cmpStruct> mostCommon(typeCounter.begin(),
                                                 typeCounter.end());

    return (*(mostCommon.begin())).first;
}

int main() {
    vector<string> bird_types1 = {"zyablik"s, "sinica"s, "vorobey"s, "zyablik"s, "sinica"s, "sinica"s};
    if (FindWidespreadBird(bird_types1) == "sinica"s) {
        cout << "Correct"s << endl;
    } else {
        cout << "Not correct"s << endl;
    }

    vector<string> bird_types2 = {"ruh"s, "sirin"s, "blue bird of fortune"s, "finist"s, "fenix"s};
    if (FindWidespreadBird(bird_types2) == "blue bird of fortune"s) {
        cout << "Correct"s << endl;
    } else {
        cout << "Not correct"s << endl;
    }
}