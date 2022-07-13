#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
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

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    // iterate over all words in text and check if they don't present in "stop_words" set.
    for (const string& word: SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }

    return words;
}

void AddDocument(vector<vector<string>>& documents,
                 const set<string>& stop_words,
                 const string& document) {
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    documents.push_back(words);
}

// Parses "text" into words and returns just those that don't present in "stop_words" set.
set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;
    istringstream iss(text);
    string word;

    while(iss >> word) {
        if (stop_words.count(word) == 0) {
            query_words.insert(word);
        }
    }

    return query_words;
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

// Returns array of id of the documents containing words from "query". Stop-words are excluded from the search.
vector<int> FindDocuments(const vector<vector<string>>& documents,
                          const set<string>& stop_words,
                          const string& query) {
    vector<int> relevant_docs_ids;
    const set<string> queryNoStopWords = ParseQuery(query, stop_words);

    for (size_t i = 0; i < documents.size(); ++i) {
        if (MatchDocument(documents[i], queryNoStopWords)) {
            relevant_docs_ids.push_back(i);
        }
    }

    return relevant_docs_ids;
}

void ComposeDocumentsDB(vector<vector<string>>& documents,
                        const int doc_count,
                        const set<string>& stop_words) {
    for (int doc_id = 0; doc_id < doc_count; ++doc_id) {
        AddDocument(documents, stop_words, ReadLine());
    }
}

void SearchPrintRelevantDocumentsIds(vector<vector<string>>& documents,
                             const set<string>& stop_words,
                             const string& query) {
    for (int document_id: FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << " }"s << endl;
    }
}

int main() {
    const set<string> stop_words = ParseStopWords(ReadLine());
    vector<vector<string>> documents;
    const int document_count = stoi(ReadLine());
    ComposeDocumentsDB(documents, document_count, stop_words);

    // read query
    const string query = ReadLine();

    SearchPrintRelevantDocumentsIds(documents, stop_words, query);
}