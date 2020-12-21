#include <iostream>
#include <fstream>
#include "../List.h"

using namespace std;

// 5. В файле input.txt задан набор целых чисел.
// Записать их в память используя свой список.
// Просматривая список, найти  наибольший и наименьший элементы
// и переставить их в начало,
// результат записать в новый список и вывести в файл Output.txt


int main() {
    List<int> list;
    ifstream input("Input.txt");
    int ch;
    while (input >> ch) {
        list.PushBack(ch);
    }
    input.close();
    for (int i = 2; i < list.getLength(); i++) {
        cout << list.At(i) << endl;
    }
    int max = list.At(0), min = list.At(0);
    for (int i = 1; i < list.getLength(); i++) {
        if (max < list.At(i)) max = list.At(i);
        if (min > list.At(i)) min = list.At(i);
    }
    list.PushFront(max);
    list.PushFront(min);
    for (int i = 2; i < list.getLength(); i++) {
        if (list.At(i) == max || list.At(i) == min) {
            list.RemoveAt(i);
        }
    }

    ofstream output;
    output.open(("Output.txt"));
    for (int i = 0; i < list.getLength(); i++) {
        output << list.At(i) << endl;
    }
    output.close();


	system("pause");
	return 0;
}