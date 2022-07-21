#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
// #include <string_view>

using std::cout; using std::cin; using std::endl;
using std::string; using std::vector; using std::pair;
using namespace std::string_literals;
using std::remove_if;

const vector<string> SplitIntoWords(const string& text) {
    std::istringstream iss(text);
    vector<string> words;
    string word;

    while (iss >> word) {
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }

    return words;
}

void PrintVector(const vector<string>& v) {
    for (const auto& word: v) {
        cout << "[" << word << "]" << " ";
    }
    cout << endl;
}

int main() {
    vector<pair<int, vector<string>>> docs_db;
    string s1 = "first document."s;
    string s2 = "second document."s;
    docs_db.emplace_back(0, SplitIntoWords(s1));
    docs_db.emplace_back(1, SplitIntoWords(s2));

    for (const auto& doc: docs_db) {
        cout << doc.first << ": ";
        PrintVector(doc.second);
    }

    return 0;
}
