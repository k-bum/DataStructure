#include "UnsortedType.hpp"
#include <iostream>
#include <new>
#include <cstddef>
using namespace std;

template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
    length = 0;
    listData = NULL;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Class destructor
{
    MakeEmpty();
}
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
    return length;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item,
    bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged.
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;        // Delete first node.
    }
    else
    {
        while (!(item==(location->next)->info))
            location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
    currentPos = NULL;
}
 
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is current item.
{
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
}

// base case가 없기 때문에 바로 종료된다.
template<class ItemType>
ItemType SumSquares_a(NodeType<ItemType>* list)
{
    if(list == NULL)
        return 0;
    else
        return (list->info * list->info) + SumSquares_a(list->next);
}

// 재귀함수가 아니다.
template<class ItemType>
ItemType SumSquares_b(NodeType<ItemType>* list)
{
    int sum = 0;
    if (list != NULL)
    {
        sum = list->info * list->info;
        sum += SumSquares_b(list->next);
    }
    else if (list == NULL)
        sum += 0;
    return sum;
}

template<class ItemType>
ItemType SumSquares_c(NodeType<ItemType>* list)
{
    if(list == NULL)
        return 0;
    else
        return list->info * list->info + SumSquares_c(list->next);
}

template<class ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list)
{
    if(list->next == NULL)
        return list->info * list->info;
    else
        return list->info * list->info + SumSquares_d(list->next);
}

// genral case의 return 값이 0이다.
template<class ItemType>
ItemType SumSquares_e(NodeType<ItemType>* list)
{
    if(list == NULL)
        return 0;
    else
        return (list->info * list->info + SumSquares_e(list->next));
}

template<class ItemType>
void UnsortedType<ItemType>::PrintSumSquares()
{
    cout << SumSquares_a(listData) << endl;
    cout << SumSquares_b(listData) << endl;
    cout << SumSquares_c(listData) << endl;
    cout << SumSquares_d(listData) << endl;
    cout << SumSquares_e(listData) << endl;
}

template<class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc_a(NodeType<ItemType>* location,
                                                     NodeType<ItemType>* minPtr)
{
    if(location != NULL)
    {
        if(location->info < minPtr->info)
            minPtr = location;
        return MinLoc(location->next, minPtr);
    }
    else
        return minPtr;
}

template<class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc_b(NodeType<ItemType> *location)
{
    if(location == NULL)
        return NULL;
    else if(location->next == NULL)
        return location;
    else
    {
        NodeType<ItemType>* minPtr = MinLoc_b(location->next);
        if(location->info < minPtr->info)
            minPtr = location;
        return minPtr;
    }
}

template<class ItemType>
void UnsortedType<ItemType>::Sort_a(NodeType<ItemType> *location)
{
    NodeType<ItemType>* minPtr;
    ItemType temp;
    
    if(location != NULL)
    {
        minPtr = MinLoc_a(location, location);
        temp = minPtr->info;
        minPtr->info = location->info;
        location->info = temp;
        Sort_a(location->next);
    }
}

template<class ItemType>
void UnsortedType<ItemType>::Sort_b(NodeType<ItemType> *location)
{
    NodeType<ItemType>* minPtr;
    ItemType temp;
    
    if (location != NULL && location->next != NULL)
    {
        minPtr = MinLoc_b(location);
        if (minPtr == location)
            Sort_b(location->next);
        else {
            temp = minPtr->info;
            minPtr->info = location->info;
            location->info = temp;
            Sort_b(location->next);
        }
    }
}

template<class ItemType>
void UnsortedType<ItemType>::Sort()
{
    NodeType<ItemType>* location = listData;
    Sort_b(location);
    
    while(location != NULL)
    {
        cout << location->info << endl;
        location = location->next;
    }
}
