#include "StackType.cpp"
#include <iostream>
using namespace std;

void ReplaceItem(StackType& st, ItemType oldItem, ItemType newItem)
{
    StackType stack;
    while(!st.IsEmpty())
    {
        ItemType item = st.Top();
        if(item == oldItem)
        {
            item = newItem;
        }
        stack.Push(item);
        st.Pop();
    }
    while(!stack.IsEmpty())
    {
        ItemType item = stack.Top();
        st.Push(item);
        stack.Pop();
    }
}

int main()
{
    StackType stackA;
    stackA.Push(3);
    stackA.Push(5);
    stackA.Push(7);
    stackA.Push(3);
    stackA.Push(8);
    stackA.Push(9);
    stackA.Push(3);
    stackA.Push(8);
    
    ReplaceItem(stackA, 3, 5);
    
    while(!stackA.IsEmpty())
    {
        ItemType item = stackA.Top();
        stackA.Pop();
        cout << "Item: " << item << endl;
    }
    cout << endl;
    
    StackType stackB;
    stackB.Push(3);
    stackB.Push(5);
    stackB.Push(7);
    stackB.Push(3);
    stackB.Push(8);
    stackB.Push(9);
    stackB.Push(3);
    stackB.Push(8);
    
    stackB.ReplaceItem(3, 5);
    
    while(!stackB.IsEmpty())
    {
        ItemType item = stackB.Top();
        stackB.Pop();
        cout << "Item: " << item << endl;
    }
    
    return 0;
}
 
