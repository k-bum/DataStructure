#include <iostream>
#include "StackType.cpp"
using namespace std;

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem)
{
    StackType temp_stack;
    ItemType temp_item;
    while(!stack.IsEmpty())
    {
        temp_item = stack.Top();
        stack.Pop();
        if(temp_item == oldItem)
        {
            temp_stack.Push(newItem);
        }
        else
        {
            temp_stack.Push(temp_item);
        }
    }
    while(!temp_stack.IsEmpty())
    {
        temp_item = temp_stack.Top();
        temp_stack.Pop();
        stack.Push(temp_item);
    }
}

int main()
{
    StackType stack;
    ItemType item;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    ReplaceItem(stack, 5, 6);
    while(!stack.IsEmpty())
    {
        item = stack.Top();
        stack.Pop();
        cout << item << endl;
    }
    
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.ReplaceItem(5, 6);
    while(!stack.IsEmpty())
    {
        item = stack.Top();
        stack.Pop();
        cout << item << endl;
    }
    
    return 0;
}
