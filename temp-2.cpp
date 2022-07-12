#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string &text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

int main() {
    string s = "test search query"s;
    vector<string> v;

    v = SplitIntoWords(s);
    for (const string &word : v) {
        cout << "[" << word << "]"
             << " ";
    }
    cout << endl;
}