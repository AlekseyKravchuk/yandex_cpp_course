#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> month_lengths{31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
    vector<string> month_names{"January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December"};
    int num_month;
    cin >> num_month;
    if (num_month >= 1 || num_month <= 12) {
        cout << "There are " << month_lengths[num_month-1] << " days in " << month_names[num_month-1] << endl;
    } else {
        cout << "Incorrect month" << endl;
    }   
}