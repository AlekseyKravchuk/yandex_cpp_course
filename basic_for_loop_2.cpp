#include <iostream>


int main() {
    int x, y;
    std::cin >> x >> y;

    int dist = y - x;
    int delta = (dist >= 0)? 1: -1;
    
    for (auto i = 0; i < std::abs(dist)+1; i++ ) {
        std::cout << (x + delta*i) << std::endl;
    }
}