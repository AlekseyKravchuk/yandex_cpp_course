#include <iostream>
#include <string>


// using namespace std;

int main() {
    // char string_two[] = "Hello, world!";
    // cout << string_two << endl;

    // string s = "hello"s;
    // cout << s.empty() << endl;

    std::string s;
    std::getline(std::cin, s); 
    if (s.empty() || s[0] == 'k') {
        std::cout << s << std::endl;
    }
}
