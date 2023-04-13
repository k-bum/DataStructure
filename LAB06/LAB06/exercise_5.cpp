#include <iostream>
#include "SortedType.cpp"
using namespace std;

int main()
{
    SortedType<int> list_a;
    SortedType<int> list_b;
    list_a.InsertItem(1);
    list_a.InsertItem(2);
    list_a.InsertItem(3);
    list_a.InsertItem(4);
    list_a.InsertItem(5);
    list_b.InsertItem(1);
    list_b.InsertItem(2);
    list_b.InsertItem(2);
    list_b.InsertItem(4);
    list_b.InsertItem(5);
    list_a.DeleteItemA(6);
    list_b.DeleteItemB(2);
    int item;
    int length_a = list_a.LengthIs();
    int length_b = list_b.LengthIs();
    list_a.ResetList();
    list_b.ResetList();
    for(int i = 0; i < length_a; i++)
    {
        list_a.GetNextItem(item);
        cout << item << " ";
    }
    cout << endl;
    for(int i = 0; i < length_b; i++)
    {
        list_b.GetNextItem(item);
        cout << item << " ";
    }
    cout << endl;
    
    return 0;
}
