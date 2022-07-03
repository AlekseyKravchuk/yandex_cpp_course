#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(string text) {
    string word;
    vector<string> v;
    istringstream iss(text);

    while (iss >> word) {
        v.push_back(word);
    }

    return v;
}


int main(){
    std::string text;

    std::getline(std::cin, text);


    return 0;
}
