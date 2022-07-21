#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;
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

int main(){
    string text = "Lorem ipsum, dolor sit! amet, consectetur? adipiscing elit. Ut porttitor.";

    cout << text << endl;

    text.erase(remove_if(text.begin(), text.end(), ispunct), text.end());
    cout << text << endl;


    return EXIT_SUCCESS;
}
