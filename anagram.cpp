#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> BuildCharCounter(const string& s) {
    map<char, int> count_dict;
    for (const auto& ch : s) {
        ++count_dict[ch];
    }
    return count_dict;
}

bool CheckAnagram(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return false;
    }

    return BuildCharCounter(s1) == BuildCharCounter(s2);
}

// напишем небольшую функцию для проверки
void CheckIsTrue(bool value) {
    if (value) {
        cout << "Test passed :)"s << endl;
    } else {
        cout << "Test failed :("s << endl;
    }
}

int main() {
    CheckIsTrue(CheckAnagram("tea"s, "eat"s));
    CheckIsTrue(!CheckAnagram("battle"s, "beatle"s));
    CheckIsTrue(!CheckAnagram("lift"s, "elevator"s));
    CheckIsTrue(CheckAnagram("ocean"s, "canoe"s));
}