#include <iostream>


int main() {
    bool state;
    for (auto i = 0; i < 10; ++i) {
        std::cin >> state;
        if (state) {
            std::cout << "Om-nom-nom :P" << std::endl;
        } else {
            std::cout << "No cake :(" << std::endl;
            break;
        }
    }
    return 0;
}
