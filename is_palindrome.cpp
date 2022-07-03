#include <iostream>
#include <string>

using namespace std;


int isPalindromeLong(const string &s) {
    auto first = s.begin();
    auto last = !s.empty()? --s.end(): s.begin();
    while (distance(first, last) >= 0) {
        if (*first == *last) {
            ++first;
            --last;
        } else {
            return 0;
        }
    }
    return 1;
}


int isPalindromeEasy(const string &s) {
    for(int i = 0; i < s.size()/2; ++i) {
        if (s[i] != s[s.size()-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    string s = "babe"s;
    cout << "Is palindrome <" << s << ">: " << isPalindromeEasy(s) << endl;

    return 0;
}
