#include <iostream>
#include "QueType.cpp"
using namespace std;

void ReplaceItem(QueType &queue, int oldItem, int newItem)
{
    QueType q;
    ItemType item;
    while(!queue.IsEmpty())
    {
        queue.Dequeue(item);
        if(item == oldItem)
            q.Enqueue(newItem);
        else
            q.Enqueue(item);
    }
    while(!q.IsEmpty())
    {
        q.Dequeue(item);
        queue.Enqueue(item);
    }
}


int main()
{
    QueType queue;
    ItemType item;
    
    queue.Enqueue(2);
    queue.Enqueue(6);
    queue.Enqueue(7);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Enqueue(6);
    queue.Enqueue(10);
    queue.Enqueue(15);
    queue.Enqueue(6);
    
    queue.ReplaceItem(6, 20);
    while(!queue.IsEmpty())
    {
        queue.Dequeue(item);
        cout << item << " ";
    }
    cout << endl;

    queue.Enqueue(2);
    queue.Enqueue(6);
    queue.Enqueue(7);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Enqueue(6);
    queue.Enqueue(10);
    queue.Enqueue(15);
    queue.Enqueue(6);
    
    ReplaceItem(queue, 6, 20);
    while(!queue.IsEmpty())
    {
        queue.Dequeue(item);
        cout << item << " ";
    }
    cout << endl;
    
    return 0;
}
