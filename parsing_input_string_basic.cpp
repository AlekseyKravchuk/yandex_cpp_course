#include <iostream>
#include <string>
#include <sstream>


int main(){
    std::string s, word;

    std::getline(std::cin, s);
    std::istringstream line(s);
    int start = 0;

    while (line >> word) {
        std::cout << word.length() + start << std::endl;
        start += word.length() + 1;
    }

    return 0;
}
