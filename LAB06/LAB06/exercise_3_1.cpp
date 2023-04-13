#include <iostream>
#include "SortedType.cpp"
using namespace std;

void MergeLists(SortedType<ItemType> &list_a, SortedType<ItemType> list_b, SortedType<ItemType> &result)
{
    ItemType item;
    list_a.ResetList();
    list_b.ResetList();
    int length_a = list_a.LengthIs();
    int length_b = list_b.LengthIs();
    for(int i = 0; i < length_a; i++) {
        list_a.GetNextItem(item);
        result.InsertItem(item);
    }
    for(int i = 0; i < length_b; i++) {
        list_b.GetNextItem(item);
        result.InsertItem(item);
    }
}

int main()
{
    SortedType<int> list_a;
    SortedType<int> list_b;
    SortedType<int> result;
    list_a.InsertItem(1);
    list_a.InsertItem(3);
    list_a.InsertItem(5);
    list_a.InsertItem(7);
    list_a.InsertItem(9);
    list_b.InsertItem(2);
    list_b.InsertItem(4);
    list_b.InsertItem(6);
    list_b.InsertItem(8);
    list_b.InsertItem(10);
//    MergeLists(list_a, list_b, result);
//    result.ResetList();
//    int length = result.LengthIs();
//    int item;
//    for(int i = 0; i < length; i++) {
//        result.GetNextItem(item);
//        cout << item << endl;
//    }

    list_a.MergeLists(list_b, result);
    result.ResetList();
    int length = result.LengthIs();
    int item;
    for(int i = 0; i < length; i++) {
        result.GetNextItem(item);
        cout << item << endl;
    }
    
    return 0;
}
