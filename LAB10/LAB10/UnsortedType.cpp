#include "UnsortedType.hpp"
#include <cstddef>
#include <new>
using namespace std;

template<class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    listData = NULL;
}

template<class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
    MakeEmpty();
}

template<class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
    NodeType_<ItemType>* tempPtr;
    
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull()
{
    NodeType_<ItemType>* location;
    try
    {
      location = new NodeType_<ItemType>;
      delete location;
      return false;
    }
    catch(bad_alloc exception)
    {
      return true;
    }
}

template<class ItemType>
int UnsortedType<ItemType>::LengthIs()
{
    return length;
}

template<class ItemType>
void UnsortedType<ItemType>::ResetList()
{
    currentPos = NULL;
}

template<class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType &item)
{
    if(currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
}

template<class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType &item, bool &found)
{
    bool moreTosearch;
    NodeType_<ItemType>* location;
    
    moreTosearch = (location != NULL);
    found = false;
    
    while (moreTosearch && !found) {
        if(location->info == item)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreTosearch = (location != NULL);
        }
    }
}

template<class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
{
    NodeType_<ItemType>* location;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
{
    NodeType_<ItemType>* location = listData;
    NodeType_<ItemType>* tempLocation;
    if(item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while (!(location->next->info) == item) {
            location = location->next;
        }
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}
