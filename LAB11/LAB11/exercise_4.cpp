#include "PQSType.cpp"
#include <iostream>
using namespace std;

int main()
{
    PQSType pqstack(50);
    int item;
    
    pqstack.Push(1);
    pqstack.Push(2);
    pqstack.Push(3);
    pqstack.Push(4);
    
    while(!pqstack.IsEmpty())
    {
        pqstack.Pop(item);
        cout << item << endl;
    }
    
    return 0;
}
