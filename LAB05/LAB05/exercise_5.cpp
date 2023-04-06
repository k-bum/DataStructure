#include <iostream>
#include "NewQueType.cpp"
using namespace std;

int main()
{
    QueType queue(5);
    ItemType item;
    
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    
    while(!queue.IsEmpty())
    {
        queue.Dequeue(item);
        cout << item << endl;
    }
}
