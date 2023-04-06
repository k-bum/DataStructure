#include "QueType.hpp"

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
    minimum_pos = 0;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = 501;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
}
QueType::~QueType()         // Class destructor
{
    delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = maxQue - 1;
    rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.
{
    if (IsFull())
        throw FullQueue();
    else
    {
        rear = (rear + 1) % maxQue;
        items[rear] = newItem;
    }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       othersiwe a EmptyQueue exception has been thrown.
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        item = items[front];
    }
}

void QueType::ReplaceItem(ItemType oldItem, ItemType newItem)
{
    for(int i = 0; i < maxQue; i++)
    {
        if(items[i] == oldItem)
            items[i] = newItem;
    }
}

bool QueType::Identical(QueType queue)
{
    int length1 = 0;
    int length2 = 0;
    int idx = 0;
    int idx1 , idx2 = 0;
    
    for(int i = 1; i < maxQue; i++)
    {
        idx = (front + i) % maxQue;
        if(idx == rear)
        {
            length1++;
            break;
        }
        else
            length1++;
    }
    
    for(int i = 1; i < queue.maxQue; i++)
    {
        idx = (front + i) % queue.maxQue;
        if(idx == rear)
        {
            length2++;
            break;
        }
        else
            length2++;
    }
    
    if(length1 != length2)
        return false;
    
    for(int i = 1; i < maxQue; i++)
    {
        idx1 = (front + i) % maxQue;
        idx2 = (front + i) % maxQue;
        if(items[idx1] != queue.items[idx2])
            return false;
    }
    
    return true;
}

int QueType::Length()
{
    int length = 0;
    int idx = 0;
    
    for(int i = 1; i < maxQue; i++)
    {
        idx = (front + i) % maxQue;
        if(idx == rear)
        {
            length++;
            break;
        }
        else
            length++;
    }
    
    return length;
}

void QueType::MinEnqueue(ItemType newItem)
{
    int idx = 0;
    int min = 100000000;
    
    for(int i = 1; i < maxQue; i++)
    {
        idx = (front + i) % maxQue;
        if(items[idx] == -1)
        {
            items[idx] = newItem;
            break;
        }
    }
    
    for(int i = 1; i < maxQue; i++)
    {
        idx = (front + i) % maxQue;
        if(min > items[idx] && items[idx] != -1)
        {
            min = items[idx];
            minimum_pos = idx;
        }
    }
}

int QueType::MinDequeue()
{
    int idx = 0;
    int min = 100000000;
    for(int i = 1; i < maxQue; i++)
    {
        idx = (front + i) % maxQue;
        if(min > items[idx] && items[idx] != -1)
        {
            min = items[idx];
            minimum_pos = idx;
        }
    }
    items[minimum_pos] = -1;
    
    return min;
}
