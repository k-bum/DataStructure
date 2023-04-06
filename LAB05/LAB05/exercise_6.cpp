#include <iostream>
#include "QueType.cpp"
using namespace std;

int main()
{
    QueType queue(6);
    ItemType item;
    queue.Enqueue(5);
    queue.Enqueue(4);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(1);
    queue.Enqueue(8);
    
    int min = 0;
    min = queue.MinDequeue();
    cout << min << endl;
    
    queue.MinEnqueue(6);
    
    while(!queue.IsEmpty())
    {
        queue.Dequeue(item);
        cout << item << " ";
    }
    cout << endl;
    
    return 0;
}
