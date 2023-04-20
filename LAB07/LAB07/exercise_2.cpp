#include "StackType.cpp"
#include <iostream>
using namespace std;

int main()
{
    StackType stack1;
    StackType stack2;
    int item;
    stack2.Push(1);
    stack2.Push(2);
    stack2.Push(3);
    stack2.Push(4);
    stack1.Copy(stack2);
    while(!stack1.IsEmpty())
    {
        item = stack1.Top();
        cout << item << endl;
        stack1.Pop();
    }
    return 0;
}
