#include <iostream>
#include <string>
#include <sstream>


int main(){
    std::string s, word;

    std::getline(std::cin, s);
    std::istringstream line(s);

    while (line >> word) {
        std::cout << "[" << word << "]" << std::endl;
    }

    return 0;
}
