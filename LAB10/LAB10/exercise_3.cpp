#include <iostream>
#include "TreeType.cpp"
using namespace std;

int Smaller(TreeType tree, int value)
{
    ItemType item;
    bool finished = false;
    int count = 0;
    
    tree.ResetTree(IN_ORDER);
    
    do
    {
        tree.GetNextItem(item, IN_ORDER, finished);
        if(item < value)
            count++;
        else
            finished = true;
    }
    while(!finished);
    
    return count;
}

int main()
{
    TreeType tree;
    
    tree.InsertItem('k');
    tree.InsertItem('f');
    tree.InsertItem('o');
    tree.InsertItem('g');
    tree.InsertItem('p');
    tree.InsertItem('c');
    tree.InsertItem('a');
    
    cout << Smaller(tree, 'g') << endl;
    
    return 0;
}
