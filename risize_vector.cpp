#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>


using namespace std;


int main() {
    string fname = "resize_vector_input.txt"s;
    ifstream in_stream{fname};
    try {
        if (!in_stream) {
            throw fname;
        } else {
            cout << "File <" << fname << "> was opened successfully." << endl;

        }
    } catch (string fname) {
        cout << fname << " was not opened.\nPlease check that the file [" << fname << "] currently exists." << endl << endl;
    }

    int n, index, count;
    string opcode;

    in_stream >> n;
    vector<bool> my_queue;

    map<string, bool> states_direct = {
        {"WORRY"s, true},
        {"HAPPY"s, false}
    };

    map<bool, string> states_reverse = {
        {true, "worry"s},
        {false, "happy"s}
    };
  
    for (int i = 0; i < n; ++i) {
        in_stream >> opcode;
    
        if (opcode == "WORRY"s || opcode == "HAPPY"s) {
            in_stream >> index;
            my_queue[index] = states_direct[opcode];
        } else if (opcode == "COME"s) {
            in_stream >> count;
            my_queue.resize(my_queue.size() + count, false);
        } else if (opcode == "LAST_WORRY"s)  {
            cout << states_reverse[my_queue.back()] << endl;
        }
    }
}