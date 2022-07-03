#include <iostream>
#include <string>

// We have to include the namespace "std::string_literals" to use the C++-string-literals.
using namespace std::string_literals;

int main() {
    

    int a = 5;
    int b;
    do {  
        std::cout << "Guess the number: "s << std::endl;  
        std::cin >> b;
    } while (a != b);
    std::cout << "You are right!"s << std::endl;
    return 0;
}
