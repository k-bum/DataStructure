#include "StackTType.hpp"
// The function definitions for class StackType.
template<class ItemType>
StackType<ItemType>::StackType()
{
    top = -1;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
    return (top == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
    return (top == MAX_ITEMS-1);
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
    if (IsFull())
        throw FullStack();
    top++;
    items[top] = newItem;
}

template<class ItemType>
void StackType<ItemType>::Pop()
{
    if(IsEmpty())
        throw EmptyStack();
    top--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    return items[top];
}
