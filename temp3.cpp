#include <cmath>
#include <cstdarg>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double semeperimeter(const vector<double>& side_lengths) {
    double sum{0};

    for(const auto& d: side_lengths) {
        sum += d;
    }

    return sum / 2.0;
}

double gerron(double a, double b, double c) {
    vector<double> v = {a, b, c};
    double p = semeperimeter(v);
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {
    double n;
    vector<double> vec;
    cout << "Type in side lengths (space-separated): ";

    while (cin >> n) {
        vec.push_back(n);
    }


    cout << "Semeperimeter: " << semeperimeter(vec) << endl;
}
