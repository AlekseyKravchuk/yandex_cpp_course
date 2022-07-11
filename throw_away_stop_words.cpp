#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>


using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;
using std::set; using std::istringstream; using std::getline;


vector<string> SplitIntoWords(string text) {
    string word;
    vector<string> v;
    istringstream iss(text);

    while(iss >> word) {
        v.push_back(word);
    }

    return v;
}


int main() {
    string stop_words, query, word;
    set<string> exclude_set;
    vector<string> result;

    getline(cin, stop_words);
    getline(cin, query);

    istringstream exclude_stream(stop_words);
    istringstream query_stream(query);


    while(exclude_stream >> word) {
        exclude_set.insert(word);
    }

    for (const auto word: SplitIntoWords(query)) {
        if (!exclude_set.count(word)) {
            result.push_back(word);
        }
    }

    for (const auto word: result) {
        cout << "[" << word << "]" << endl;
    }

    return 0;
}
