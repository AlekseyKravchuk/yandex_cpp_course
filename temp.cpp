#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main() {
    map<string, int> legs_count = {{"dog"s, 4}, {"ostrich"s, 2}};

    // Аналогично for (const pair<string, int>& entry : legs_count)
    /*     for (const auto& entry : legs_count) {
            cout << entry.first << " has " << entry.second << " legs." << endl;
        } */

    // Пару из двух значений можно создать на лету фигурными скобками, а затем вставить в словарь методом insert() как ключ и значение:
    const auto [octopus_iterator, success_flag] = legs_count.insert({"octopus"s, 8});

    cout << success_flag << endl;
    for (const auto& [animal, number_of_legs] : legs_count) {
        cout << animal << " has " << number_of_legs << " legs." << endl;
    }

    return 0;
}
