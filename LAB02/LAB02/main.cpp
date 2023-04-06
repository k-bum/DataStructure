#include <iostream>
#include "ItemType.cpp"
#include "Unsorted.cpp"
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream input_file(argv[1]); //mac file
    ofstream output_file(argv[2]); //window file

    char ch;
    while (!input_file.eof()) {
        input_file.get(ch);
        if (input_file.eof())
            break;
        if (input_file.fail())
            break;
        if (ch == 0x0D) {
            output_file << '\n';
        }
        else
            output_file << ch;
    }
    input_file.close();
    output_file.close();

    return 0;
}

/* test code for Unsorted.cpp
int main() {
    UnsortedType list;
    ItemType item1;
    ItemType item2;
    ItemType item3;
    ItemType item4;
    ItemType item5;
    ItemType item6;
    item1.Initialize(1);
    item2.Initialize(2);
    item3.Initialize(3);
    item4.Initialize(4);
    item5.Initialize(5);
    item6.Initialize(4);
    list.InsertItem(item1);
    list.InsertItem(item2);
    list.InsertItem(item3);
    list.InsertItem(item4); //[1, 2, 3, 4]
    list.DeleteItem_a(item5);
    cout << list.LengthIs() << endl;
    list.InsertItem(item6); //[1, 2, 3, 4, 4]
    list.DeleteItem_c(item6);
    cout << list.LengthIs() << endl;
    return 0;
}
*/
