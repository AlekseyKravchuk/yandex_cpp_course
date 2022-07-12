#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

// takes string by ref and returns vector of tokens
const vector<string> SplitIntoWords(const string& text) {
    std::istringstream iss(text);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}

set<string> ParseStopWordsIntoSet(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop2Vector(const string& text, const set<string>& stop_words) {
    vector<string> words;
    string word;
    istringstream iss(text);

    while (iss >> word) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }

    return words;
}

// Parse text into tokens and return just those which aren't present in "stop_words" set.
set<string> ParseQueryIntoSet(const string& text, const set<string>& stop_words) {
    istringstream iss(text);
    string word;
    set<string> query_words;

    while (iss >> word) {
        if (stop_words.count(word) == 0) {
            query_words.insert(word);
        }
    }

    return query_words;
}

void AddDocument(vector<vector<string>>& documents,
                 const set<string>& stop_words,
                 const string& document) {
    const vector<string> words = SplitIntoWordsNoStop2Vector(document, stop_words);
    documents.push_back(words);
}

// Returns "true" if "document_words" vector contains strings from "query_words" set.
bool MatchDocument(const vector<string>& document_words, const set<string>& query_words) {
    for (const auto& word : document_words) {
        if (query_words.count(word) == 1) {
            return true;
        }
    }

    return false;
}

// Returns array of documents id which contains words from "query". Stop-words are excluded from the search.
vector<int> FindDocuments(const vector<vector<string>>& documents,
                          const set<string>& stop_words,
                          const string& query) {
    vector<int> relevant_docs_id;

    for (size_t i = 0; i < documents.size(); ++i) {
        if (MatchDocument(documents[i], ParseQueryIntoSet(query, stop_words))) {
            relevant_docs_id.push_back(i);
        }
    }

    return relevant_docs_id;
}

void ComposeDocumentsDB(vector<vector<string>>& documents,
                        const int doc_count,
                        const set<string>& stop_words) {
    for (int doc_id = 0; doc_id < doc_count; ++doc_id) {
        AddDocument(documents, stop_words, ReadLine());
    }
}

void SearchRelevantDocuments(vector<vector<string>>& documents,
                             const set<string>& stop_words,
                             const string& query) {
    for (int document_id : FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << " }"s << endl;
    }
}

int main() {
    vector<vector<string>> documents;
    const set<string> stop_words = ParseStopWordsIntoSet(ReadLine());
    const int doc_count = stoi(ReadLine());

    ComposeDocumentsDB(documents, doc_count, stop_words);

    const string query = ReadLine();
    SearchRelevantDocuments(documents, stop_words, query);

    return 0;
}