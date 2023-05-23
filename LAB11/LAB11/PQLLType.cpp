#include "PQLLType.hpp"

template<class ItemType>
PQLLType<ItemType>::PQLLType()
{
    length = 0;
}

template<class ItemType>
void PQLLType<ItemType>::MakeEmpty()
{
    length = 0;
    linkedlist.MakeEmpty();
}

template<class ItemType>
PQLLType<ItemType>::~PQLLType()
{
    linkedlist.~SortedType();
}

// Heap / Linked Sorted List:
// Enqueue: O(log(N)) / O(N)
// Dequeue: O(log(N)) / O(1)
template<class ItemType>
void PQLLType<ItemType>::Enqueue(ItemType newItem)
{
    if(linkedlist.IsFull())
        throw FullPQLL();
    else
    {
        length++;
        linkedlist.InsertItem(newItem);
    }
}

template<class ItemType>
void PQLLType<ItemType>::Dequeue(ItemType& item)
{
    if(length == 0)
        throw EmptyPQLL();
    else
    {
        linkedlist.ResetList();
        linkedlist.GetNextItem(item);
        linkedlist.DeleteItem(item);
        length--;
    }
}

template<class ItemType>
bool PQLLType<ItemType>::IsFull() const
{
    return linkedlist.IsFull();
}

template<class ItemType>
bool PQLLType<ItemType>::IsEmpty() const
{
    return length == 0;
}
