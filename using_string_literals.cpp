#include <iostream>
#include <string>

/* 
We have to include the namespace "std::string_literals" in line (1) to use the C++-string-literals.
Line (2) is the critical line in the example. I use the C-string-literal "hello" to create a C++ string.
This is the reason that the type of firstPair is (std::string, int),
but the type of the secondPair is (const char*, int). In the end, the comparison in line (5) fails,
because you can not compare different types. Look carefully at the last line of the ERROR message:
‘std::pair<std::__cxx11::basic_string<char>, int>’ is not derived from
‘const __gnu_cxx::__normal_iterator<_Iterator, _Container>’
*/
 

int main() {
    using namespace std::string_literals;                         // (1)

    std::string my_str = "hello";                                 // (2)
    
    auto firstPair = std::make_pair(my_str, 5);
    // auto secondPair = std::make_pair("hello", 15);             // (3)
    auto secondPair = std::make_pair("hello"s, 15);               // (4)
    
    if (firstPair < secondPair) {
        std::cout << "true" << std::endl;                         // (5)
    }
    return 0;
}
