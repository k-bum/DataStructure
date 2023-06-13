#include "HashTable.hpp"
#include "Student.cpp"
#include <iostream>
using namespace std;

int main()
{
    Student stu[100];
    stu[0].InitValue(2003200111, "이웅재", 3.0);
    stu[1].InitValue(2004200121, "권오준", 3.2);
    stu[2].InitValue(2005200132, "김진일", 2.7);
    
    HashTable<Student> ht(stu[0]);
    ht.InsertItem(stu[0]);
    ht.InsertItem(stu[1]);
    ht.InsertItem(stu[2]);
    
    string input;
    cin >> input;
    Student myStu;
    myStu.InitValue(0, input, 0.0);
    
    bool found;
    ht.RetrieveItem(myStu, found);
    cout << myStu.getName() << endl;

    return 0;
}
