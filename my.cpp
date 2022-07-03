# include <iostream>
// # include <string>

using namespace std;

int main(){
    // Declaring a string object
    string s1 = "My first string"s;
    string s2;
    // cout << "Enter desired string: ";

    // Такая конструкция считает только первое слово в строке, т.е. до первого пробельного символа
    // При считывании строки из cin она считывается до первого пробельного символа.
    // При этом пробелы между словами не считываются:
    // cin >> s1;

    // Чтобы считать всю строку, а не только текущее слово, используют функцию getline.
    // Она считывает символы из потока ввода в строку, пока не встретится символ конца строки либо не произойдёт ошибка. 
    // getline(cin, s1);
    cout << "You have typed in the following string: " << s1 << endl;
    if (s2.empty()){
        cout << "String s2 is empty." << endl;
    }

    return 0;
}