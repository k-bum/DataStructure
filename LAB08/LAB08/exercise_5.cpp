#include "UnsortedType.cpp"

int main()
{
    UnsortedType<int> list;
    list.InsertItem(8);
    list.InsertItem(6);
    list.InsertItem(1);
    list.InsertItem(4);
    
    list.Sort();
}

