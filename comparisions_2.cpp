#include <iostream>
#include <string>


int main() {
    int x, y, user_sum;
    std::cin >> x >> y >> user_sum;
    int actual_sum = x + y;

    if (user_sum != actual_sum) {
        std::cout << "Error. The sum of " << x << " and " << y << " is " << actual_sum << std::endl;
    }

    return 0;
}