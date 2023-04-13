#include <iostream>
#include "QueType.cpp"
using namespace std;

void ReplaceItem(QueType<ItemType> &queue, ItemType oldItem, ItemType newItem)
{
    QueType<ItemType> temp_queue;
    ItemType item;
    while (!queue.IsEmpty())
    {
        queue.Dequeue(item);
        if(item == oldItem)
        {
            temp_queue.Enqueue(newItem);
        }
        else
        {
            temp_queue.Enqueue(item);
        }
    }
    while (!temp_queue.IsEmpty())
    {
        temp_queue.Dequeue(item);
        queue.Enqueue(item);
    }
}

int main()
{
    QueType<int> queue;
    int item;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    ReplaceItem(queue, 5, 6);
    while(!queue.IsEmpty())
    {
        queue.Dequeue(item);
        cout << item << endl;
    }
    
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.ReplaceItem(5, 6);
    while(!queue.IsEmpty())
    {
        queue.Dequeue(item);
        cout << item << endl;
    }
    
    return 0;
}
