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

void FindWidespreadBird(const vector<string>& types) {
    map<string, int> birds_types_counter;
    set<pair<int, string>> most_common;

    // flip the pairs
    for (auto const& [key, value] : birds_types_counter) {
        most_common.emplace(value, key);
    }

    set<pair<int, string>>::iterator it;
    for (it = most_common.begin(); it != most_common.end(); ++it) {
        cout << (*it).first << ": " << (*it).second << endl;
    }

    // set<pair<int, string>>::reverse_iterator rev_it;
    // for (rev_it = most_common.rbegin(); rev_it != most_common.rend(); ++rev_it) {
    //     cout << (*rev_it).second << ": " << (*rev_it).first << endl;
    // }

    cout << "!!!!!!!!!!!!!!!!!" << endl;

    // ========= NOT WORKING CODE =========
    // set<pair<int, string>>::reverse_iterator rev_it = most_common.rbegin();
    // auto obj = (*rev_it);
    // cout << left << setw(10) << obj.second << setw(4) << obj.first << endl;

    // set<pair<int, string>>::reverse_iterator rev_it;
    // for (rev_it = most_common.rbegin(); rev_it != most_common.rend(); ++rev_it) {
    //     cout << left << setw(10) << (*rev_it).second << setw(4) << (*rev_it).first << endl;
    // }
}

int main() {
    vector<string> bird_types1 = {"zyablik"s, "sinica"s, "vorobey"s, "zyablik"s, "sinica"s, "sinica"s};
    FindWidespreadBird(bird_types1);
    cout << "OK!!!!!!!!!" << endl;

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