#include <iostream>
using namespace std;

const int MAX_ITEMS = 200;

class FullStack
{};

class EmptyStack
{};

class DoubleStack
{
private :
    int top_small;
    int top_big;
    int items[MAX_ITEMS];
    
public :
    DoubleStack();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(int item);
    void Print() const;
};

DoubleStack::DoubleStack()
{
    top_small = 0;
    top_big = 199;
}


bool DoubleStack::IsFull() const
{
    return ((top_small + 1) == top_big);
}

bool DoubleStack::IsEmpty() const
{
    return ((top_small == 0) && (top_big == 199));
}

void DoubleStack::Push(int item)
{
    if(!IsFull())
    {
        if(item <= 1000)
        {
            items[top_small] = item;
            top_small++;
        }
        else
        {
            items[top_big] = item;
            top_big--;
        }
    }
    else
        throw FullStack();
}

void DoubleStack::Print() const
{
    if(IsEmpty())
        throw EmptyStack();
    for(int first = top_small - 1; first >= 0; first--)
        cout << items[first] << " ";
    cout << endl;
    for(int last = top_big + 1; last <= 199; last++)
        cout << items[last] << " ";
    cout << endl;
}

int main()
{
    DoubleStack doublestack;
    doublestack.Push(1);
    doublestack.Push(2);
    doublestack.Push(3);
    doublestack.Push(4);
    doublestack.Push(1003);
    doublestack.Push(1004);
    doublestack.Push(1005);
    doublestack.Print();
    return 0;
}
