#include <iostream>
#include <vector>
#include <sstream>

struct Building {
    std::string color;
    int num_floors;
};


int main() {
    std::vector<Building> buildings;
    std::string line;
    std::string color;
    int num_floors;

    std::getline(std::cin, line);
    std::istringstream record(line);

    while(record >> color >> num_floors) {
        buildings.push_back(Building{color, num_floors});
    }

    Building info = buildings.back();
    buildings.pop_back();
        for (auto it = buildings.begin(); it != buildings.end(); it++) {
        int index = std::distance(buildings.begin(), it) + 1;  // !!! 1-based index !!!
        if (info.color == "?") {
            if (info.num_floors == -1) {
                // если вообще нет никакой информации, заходим в каждый дом
                std::cout << index << std::endl;
            } else {
                // если известна только этажность, то заходим в дом с совпадающей этажностью
                if ((*it).num_floors == info.num_floors) {
                    std::cout << index << std::endl;
                }
            }
        }
        else { // если задан цвет дома
            if (info.num_floors == -1) { // но не задана его этажность => посещаем каждый дом с совпадающим цветом
                if ((*it).color == info.color) {
                    std::cout << index << std::endl;
                }
            } else {
                if ((*it).color == info.color && (*it).num_floors == info.num_floors) {
                    std::cout << index << std::endl;
                }
            }
        }
    }

    return 0;
}
