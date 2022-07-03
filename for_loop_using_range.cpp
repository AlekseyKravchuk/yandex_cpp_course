#include <iostream>
#include <vector>
#include "range.hpp"

// using namespace std;

struct Building {
    std::string color;
    int num_floors;
};

int main() {
    using std::cout;
    using util::lang::range;
    using util::lang::indices;

    cout << "Basic usage: iterating over a range of numbers.\n";
    for (auto i : range(1, 5)) {
        cout << i << " ";
    }

    return 0;
}