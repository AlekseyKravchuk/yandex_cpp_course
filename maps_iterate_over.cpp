#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> BuildReversedMap(const map<string, string>& input_map) {
    map<string, string> resversed_map;
    for (const auto& [key, value]: input_map) {
        // resversed_map.insert({value, key});
        resversed_map[value] = key;
    }

    return resversed_map;
}

int main() {


    map<string, string> test1_input = {{"cat"s, "felis catus"s}, 
                                       {"dog"s, "canis lupus"s}};
    map<string, string> test1_output = {{"felis catus"s, "cat"s}, 
                                        {"canis lupus"s, "dog"s}};

    // Проверяем корректность BuildReversedMap на примере 
    if (BuildReversedMap(test1_input) != test1_output) {
        cout << "BuildReversedMap returned wrong dictionary"s << endl;
    }

    // // Добавьте ещё тесты, чтобы убедиться, что ваша функция работает верно
    return 0;
}