#include <iostream>
#include "UnsortedType.cpp"
using namespace std;

void MergeLists(UnsortedType<ItemType> &list_a, UnsortedType<ItemType> &list_b, UnsortedType<ItemType> &result)
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
    UnsortedType<int> ulist_a;
    UnsortedType<int> ulist_b;
    UnsortedType<int> result;
    ulist_a.InsertItem(1);
    ulist_a.InsertItem(3);
    ulist_a.InsertItem(5);
    ulist_a.InsertItem(7);
    ulist_a.InsertItem(9);
    ulist_b.InsertItem(2);
    ulist_b.InsertItem(4);
    ulist_b.InsertItem(6);
    ulist_b.InsertItem(8);
    ulist_b.InsertItem(10);
    MergeLists(ulist_a, ulist_b, result);
    int length = result.LengthIs();
    int item;
    for(int i = 0; i < length; i++) {
        result.GetNextItem(item);
        cout << item << endl;
    }
    
    return o;
}
