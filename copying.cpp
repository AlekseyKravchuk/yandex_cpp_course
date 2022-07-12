// final050.cpp

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string &text) {
    vector<string> words;
    string word;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            words.push_back(word);
            word = ""s;
        } else {
            word += text[i];
        }
    }
    words.push_back(word);

    return words;
}

set<string> ParseStopWordsIntoSet(const string &text) {
    set<string> stop_words;
    for (const string &word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> ParseQuery(const string &text, const set<string> &stop_words) {
    vector<string> words;
    for (const string &word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

int main() {
    // Read stop words
    string stop_words_joined;
    getline(cin, stop_words_joined);
    set<string> stop_words = ParseStopWordsIntoSet(stop_words_joined);

    // Read query
    string query;
    getline(cin, query);
    vector<string> query_words = ParseQuery(query, stop_words);

    for (string word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}