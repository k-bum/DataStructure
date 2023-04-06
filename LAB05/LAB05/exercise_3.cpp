#include <iostream>
#include "QueType.cpp"
using namespace std;

bool Identical(QueType queue1, QueType queue2)
{
    ItemType item1;
    ItemType item2;
    
    while(!queue1.IsEmpty() && !queue2.IsEmpty())
    {
        queue1.Dequeue(item1);
        queue2.Dequeue(item2);
        if(item1 == item2)
            continue;
        else
            return false;
    }
    
    if(!queue1.IsEmpty() || !queue2.IsEmpty())
        return false;
    else
        return true;
}

int main()
{
    QueType queue1(10);
    QueType queue2(10);
    queue1.Enqueue(2);
    queue1.Enqueue(6);
    queue1.Enqueue(7);
    queue1.Enqueue(4);
    queue1.Enqueue(5);
    queue2.Enqueue(2);
    queue2.Enqueue(6);
    queue2.Enqueue(7);
    queue2.Enqueue(4);
    queue2.Enqueue(5);
    if(queue1.Identical(queue2) == true)
        cout << "True" << endl;
    else
        cout << "False" << endl;

//    queue1.Enqueue(2);
//    queue1.Enqueue(6);
//    queue1.Enqueue(7);
//    queue1.Enqueue(4);
//    queue1.Enqueue(5);
//    queue2.Enqueue(2);
//    queue2.Enqueue(6);
//    queue2.Enqueue(7);
//    queue2.Enqueue(4);
//    queue2.Enqueue(5);
//
//    if(Identical(queue1, queue2) == true)
//        cout << "True" << endl;
//    else
//        cout << "False" << endl;
//
    return 0;
}
