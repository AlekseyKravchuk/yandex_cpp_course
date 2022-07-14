#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

map<string, int> MakeBirdSpeciesCounter(const vector<string>& types) {
    map<string, int> birds_types_counter;

    for (auto const& bird_species : types) {
        ++birds_types_counter[bird_species];
    }

    return birds_types_counter;
}

// Comparison function for sorting the set by increasing order of its pair's second value
struct cmpStruct {
    template <typename T>

    // Comparator function for "set<pair<int, string>, cmpStruct>"
    // pair.first:  int, the number of bird species occurences
    // pair.second: string,  bird species name
    bool operator()(const T& lhs, const T& rhs) const {
        if (lhs.second != rhs.second) {
            return lhs.second > rhs.second;
        }
        return lhs.first > rhs.first;
    }
};

// string FindWidespreadBird(const vector<string>& types) {
//     map<string, int> birds_types_counter = MakeBirdSpeciesCounter(types);
//     set<pair<int, string>, cmpStruct> most_common;

//     // flip the pairs using set of pairs: pair<int, string>
//     for (auto const& [key, value] : birds_types_counter) {
//         most_common.emplace(value, key);
//     }

//     return (*(most_common.begin())).second;
// }

void FindWidespreadBird(const vector<string>& types) {
    map<string, int> M = MakeBirdSpeciesCounter(types);
    set<pair<int, string>, cmpStruct> most_common(M.begin(), M.end());

    // flip the pairs using set of pairs: pair<int, string>
    // for (auto const& [key, value] : birds_types_counter) {
    //     most_common.emplace(value, key);
    // }

    for (const auto& elm : most_common) {
        cout << elm.first << ": " << elm.second << endl;
    }
}

int main() {
    vector<string> bird_types1 = {"zyablik"s, "sinica"s, "vorobey"s, "zyablik"s, "sinica"s, "sinica"s};
    FindWidespreadBird(bird_types1);
    // if (FindWidespreadBird(bird_types1) == "sinica"s) {
    //     cout << "Correct"s << endl;
    // } else {
    //     cout << "Not correct"s << endl;
    // }

    // vector<string> bird_types2 = {"ruh"s, "sirin"s, "blue bird of fortune"s, "finist"s, "fenix"s};
    // if (FindWidespreadBird(bird_types2) == "blue bird of fortune"s) {
    //     cout << "Correct"s << endl;
    // } else {
    //     cout << "Not correct"s << endl;
    // }

    return 0;
}