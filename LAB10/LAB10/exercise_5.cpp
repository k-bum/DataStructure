#include "UnsortedType.cpp"
#include "TreeType.cpp"
#include <iostream>
using namespace std;

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list)
{
    int list_length = list.LengthIs();
    int tree_length = tree.LengthIs();
    
    if(list_length != tree_length)
        return false;
    else
    {
        ItemType item;
        bool found;
        list.ResetList();
        
        for(int i = 0; i < list_length; i++)
        {
            list.GetNextItem(item);
            tree.RetrieveItem(item, found);
            if(!found)
                return false;
        }
        return true;
    }
}

bool MatchingItem_Tree(TreeType& tree, UnsortedType<ItemType>& list)
{
    int list_length = list.LengthIs();
    int tree_length = tree.LengthIs();
    
    if(list_length != tree_length)
        return false;
    else
    {
        ItemType item;
        bool found;
        tree.ResetTree(IN_ORDER);
        
        for(int i = 0; i < tree_length; i++)
        {
            tree.GetNextItem(item, IN_ORDER, found);
            list.RetrieveItem(item, found);
            if(!found)
                return false;
        }
        return true;
    }
}

int main()
{
    TreeType tree;
    UnsortedType<char> list;
    
    tree.InsertItem('g');
    tree.InsertItem('b');
    tree.InsertItem('k');
    tree.InsertItem('a');
    tree.InsertItem('e');
    tree.InsertItem('h');
    tree.InsertItem('z');
    
    list.InsertItem('g');
    list.InsertItem('b');
    list.InsertItem('k');
    list.InsertItem('a');
    list.InsertItem('e');
    list.InsertItem('h');
    list.InsertItem('z');
    
    cout << MatchingItem_Tree(tree, list) << endl;
    cout << MatchingItem_Unsorted(tree, list) << endl;
    return 0;
}
