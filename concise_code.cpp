#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/* vector<string> SplitIntoWords(const string& text) {
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
} */


const vector<string> SplitIntoWords(const string& text) {
    std::istringstream iss(text);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

const vector<string> ParseQuery(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

string ReadLine() {
    string line;
    getline(cin, line);
    return line;
}

void PrintQueryWordsExcludingStopWords(const vector<string>& query_words) {
    for (const string& word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}

int main() {
    const set<string> stop_words = ParseStopWords(ReadLine());
    const vector<string> query_words = ParseQuery(ReadLine(), stop_words);
    PrintQueryWordsExcludingStopWords(query_words);
}