#include "NewQueType.hpp"

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, rear and length have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = max;
    front = 0;
    rear = 0;
    items = new ItemType[maxQue];
    length = 0;
    
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, rear and length have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = 500;
    front = 0;
    rear = 0;
    items = new ItemType[maxQue];
    length = 0;
}
QueType::~QueType()         // Class destructor
{
    delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = 0;
    rear = 0;
    length = 0;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (length == 0);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return (length == maxQue);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.
{
    if (IsFull())
        throw FullQueue();
    else
    {
        length++;
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
        length--;
        front = (front + 1) % maxQue;
        item = items[front];
    }
}
