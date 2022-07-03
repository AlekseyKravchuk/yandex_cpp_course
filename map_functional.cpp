#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<int, std::string> dict = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {42, "Don\'t Panic!!!"}
    };

    int key2search;
    std::cin >> key2search;

    // //=>1-st way to check if dict contains "key2search"
    // if (dict.find(key2search) == dict.end()) {
    //     // NOT FOUND
    // } else {
    //     // FOUND
    // }

    // //=>2-nd way to check if dict contains "key2search"
    // if (dict.count(key2search) > 0) {
    //     // FOUND
    // } else {
    //     // NOT FOUND
    // }

/*  if (dict.count(key2search) > 0) {
        std::cout << "Key " << key2search << " found." << std::endl;
    } else {
        std::cout << "Key " << key2search << " NOT found." << std::endl;
    } */

    // multiline comment, /*...*/: Ctrl+Shift+A
    // single line comment, //: Ctrl + /
    // 
    if (dict.find(key2search) == dict.end()) {
       std::cout << "Key " << key2search << " NOT found." << std::endl;
    } else {
        std::cout << "Key " << key2search << " found." << std::endl;
    }
}