#include <iostream>
#include <tuple>
#include <algorithm>


int main() {
    int x, y;

    std::cin >> x >> y;
    std::tie(x, y) = std::minmax({x, y});

    std::cout << "min = " << x << ", max = " << y << std::endl;
    
    for (auto i = x; i <= y; i++) {
        std::cout << i << std::endl;
    }
}