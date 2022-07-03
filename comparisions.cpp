#include <iostream>
#include <string>
#include <map>


int main() {
    std::map<std::string, int> houses;
    std::string color, key2search;

    for (auto i = 1; i <=3; i++) {
        std::cin >> color;
        houses[color] = i;
    }

    std::cin >> key2search;
    auto it = houses.find(key2search);
    
    if (it == houses.end()) {
        // Key NOT FOUND!!!
        std::cout << "Seek somewhere else" << std::endl;
    } else {
        std::cout << "Enter the house " << (*it).second << std::endl;
    }

    return 0;
}