#include <iostream>
#include <stdlib.h>
#include "QueType.cpp"
using namespace std;

int main() {
    
    QueType queue(10);
    
    for(int i = 0; i < 10; i++)
    {
        int a = rand() % 10;
        cout << a << " ";
        queue.Enqueue(a);
    }
    cout << endl;
    
    ItemType item;
    while(!queue.IsEmpty())
    {
        queue.Dequeue(item);
        cout << item << " ";
    }
    cout << endl;
    
    return 0;
}
