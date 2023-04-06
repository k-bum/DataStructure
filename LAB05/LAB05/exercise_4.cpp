#include <iostream>
#include "QueType.cpp"
using namespace std;

int Length(QueType queue)
{
    QueType q;
    int length = 0;
    ItemType item;
    while(!queue.IsEmpty())
    {
        queue.Dequeue(item);
        length++;
        q.Enqueue(item);
    }
    while(!q.IsEmpty())
    {
        q.Dequeue(item);
        queue.Enqueue(item);
    }
    return length;
}

int main()
{
    QueType queue(7);
    queue.Enqueue(2);
    queue.Enqueue(6);
    queue.Enqueue(7);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Enqueue(6);
    queue.Enqueue(10);
    //cout << Length(queue) << endl;
    cout << queue.Length() << endl;
    return 0;
}
