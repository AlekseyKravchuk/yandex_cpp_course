#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

// using namespace std;
using std::cin;
using std::cout;
using std::endl;
using namespace std::string_literals;
using std::istringstream;
using std::pair;
using std::set;
using std::string;
using std::vector;

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

    // remove all the puntctuations in "word"
    word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());

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

vector<string> SplitIntoWordsNoStop(const string& text,
                                    const set<string>& stop_words) {
    vector<string> words;

    // iterate over all words in text and check if they don't present in "stop_words" set.
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }

    return words;
}

void AddDocument(vector<pair<int, vector<string>>>& documents,
                 const set<string>& stop_words,
                 int document_id,
                 const string& document) {
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    documents.emplace_back(document_id, words);

    // Another way to insert pair into vector:
    // documents.push_back(pair<int, vector<string>>{document_id, words});
}

// Parses "text" into words and returns just those that don't present in "stop_words" set.
set<string> ParseQuery(const string& text,
                       const set<string>& stop_words) {
    set<string> query_words;
    istringstream iss(text);
    string word;

    while (iss >> word) {
        if (stop_words.count(word) == 0) {
            query_words.insert(word);
        }
    }

    return query_words;
}

// Returns document_relevance.
int MatchDocument(const pair<int, vector<string>>& content,
                  const set<string>& query_words) {
    set<string> matched_words;

    if (query_words.empty()) {
        return 0;
    }

    for (const string& word : content.second) {
        if (query_words.count(word) == 1) {
            matched_words.insert(word);
        }
    }

    return static_cast<int>(matched_words.size());
}

// Returns array of pairs: {document_id: int, relevance: int}
// id of the documents containing words from "query". Stop-words are excluded from the search.
vector<pair<int, int>> FindDocuments(const vector<pair<int, vector<string>>>& documents,
                                     const set<string>& stop_words,
                                     const string& query) {
    vector<pair<int, int>> relevant_docs;
    const set<string> queryNoStopWords = ParseQuery(query, stop_words);

    for (const auto& content : documents) {
        int relevance = MatchDocument(content, queryNoStopWords);

        if (relevance) {
            relevant_docs.emplace_back(content.first, relevance);
        }
    }

    return relevant_docs;
}

void ComposeDocumentsDB(vector<pair<int, vector<string>>>& documents,
                        const int doc_count,
                        const set<string>& stop_words) {
    for (int doc_id = 0; doc_id < doc_count; ++doc_id) {
        AddDocument(documents, stop_words, doc_id, ReadLine());
    }
}

void SearchPrintRelevantDocumentsIds(vector<pair<int, vector<string>>>& documents,
                                     const set<string>& stop_words,
                                     const string& query) {
    for (const auto& [document_id, relevance] : FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s << endl;
    }
}

int main() {
    const set<string> stop_words = ParseStopWords(ReadLine());
    vector<pair<int, vector<string>>> documents;
    const int document_count = stoi(ReadLine());
    ComposeDocumentsDB(documents, document_count, stop_words);

    // read query
    const string query = ReadLine();

    SearchPrintRelevantDocumentsIds(documents, stop_words, query);
}