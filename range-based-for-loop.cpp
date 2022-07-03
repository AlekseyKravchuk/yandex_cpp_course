#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;


int main() {
    vector<string> v;
    string s, word;

    getline(cin, s);
    istringstream line(s);

    while (line >> word) {
        v.push_back(word);
    }

    for (auto it: v) {
        cout << "[" << it << "]" << endl;
    }
    
    return 0;
}
