#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
#include <tuple>


using namespace std;


tuple<int, vector<string>> CalculateSimilarity(vector<string> first, vector<string> second) {
    // верните размер пересечения множеств слов first и second
    set<string> set_1(first.begin(), first.end());
    set<string> set_2(second.begin(), second.end());
    vector<string> common_data;
    set_intersection(set_1.begin(), set_1.end(),
                    set_2.begin(), set_2.end(),
                    std::back_inserter(common_data));
    
    return make_tuple(common_data.size(), common_data);
}

// SplitIntoWords разбивает строку text на слова и возвращает их в виде вектора
// Слово - последовательность непробельных символов,
// разделённых одним или более пробелов.
vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    istringstream line(text);
    while(line >> word) {
        words.push_back(word);
    }
    
    return words;
}

int main() {
    string query, description;

    getline(cin, query);
    getline(cin, description);

    int n;
    vector<string> v;

    tie(n, v) = CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description));

    cout << n << endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
       if (it != v.end() - 1) {
        cout << *it << ", ";
       } else {
        cout << *it << endl;
       }
    }
    
}