#include <iostream>
#include <string>

int main() {
    double d1, d2, dif;
    std::cin >> d1 >> d2;
    dif = std::abs(d1 - d2);

    if (d1 == d2) {
        std::cout << "The orange is divided into two equal parts" << std::endl;
    } else if (d1 > d2) {
        std::cout << "Cut off " <<  dif << " from the first part" << std::endl;
    } else {
        std::cout << "Cut off " <<  dif << " from the second part" << std::endl;
    }
    return 0;
}