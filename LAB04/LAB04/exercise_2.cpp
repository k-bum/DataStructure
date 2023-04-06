#include <iostream>
#include "StackTType.cpp"
using namespace std;

StackType<int> CopyStack(StackType<int>& stackA)
{
    StackType<int> stackB;
    StackType<int> stackC;
    while(!stackA.IsEmpty())
    {
        int elem = stackA.Top();
        stackC.Push(elem);
        stackA.Pop();
    }
    while(!stackC.IsEmpty())
    {
        int elem = stackC.Top();
        stackB.Push(elem);
        stackC.Pop();
    }
    return stackB;
}

int main() {
    StackType<int> stackA;
    stackA.Push(3);
    stackA.Push(5);
    stackA.Push(7);
    stackA.Push(4);
    stackA.Push(8);
    stackA.Push(9);
    
    StackType<int> stackB;
    stackB = CopyStack(stackA);
    while(!stackB.IsEmpty())
    {
        int result = stackB.Top();
        stackB.Pop();
        cout << result << endl;
    }
    
    return 0;
}
