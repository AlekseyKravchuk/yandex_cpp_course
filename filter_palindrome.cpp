#include <iostream>
#include <string>
#include <vector>


using namespace std;


bool IsPalindrome(string s) {
    int len = s.size();
    for (int i = 0; i < len/2; ++i) {
        if (s[i] != s[len-1-i]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromeFilter(vector<string> words, int min_length) {
    // Возвращает из words все строки-палиндромы длиной не меньше min_length
    // Эта функция должна вызывать написанную выше функцию IsPalindrome
    vector<string> res;

    for (auto word: words) {
        if (IsPalindrome(word) && word.size() >= min_length) {
            res.push_back(word);
        }
    }
    return res;
}

int main() {
    // vector<string> v = {"rotor", "anna", "kayak"};
    // auto res = PalindromeFilter(v, 5);
    vector<string> v = {"racecar", "bro", "code"};
    auto res = PalindromeFilter(v, 4);

    for (auto it = res.begin(); it != res.end(); ++it) {
        if (it != res.end() - 1) {
            cout << (*it) << ", ";
        } else {
            cout << (*it) << endl;
        }
    }

    return 0;
}
