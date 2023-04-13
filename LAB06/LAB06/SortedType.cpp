#include "SortedType.hpp"
#include <cstddef>
#include <new>
using namespace std;

template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
SortedType<ItemType>::SortedType()  // Class constructor
{
    length = 0;
    listData = NULL;
}

template<class ItemType>
bool SortedType<ItemType>::IsFull() const
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
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
    return length;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
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
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
    if (location->info < item)
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else if (item == location->info)
    {
      found = true;
      item = location->info;
    }
    else
      moreToSearch = false;
    }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    NodeType<ItemType>* newNode;  // pointer to node being inserted
    NodeType<ItemType>* predLoc;  // trailing pointer
    NodeType<ItemType>* location; // traveling pointer
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);

    // Find insertion point.
    while (moreToSearch)
    {
        if (location->info < item)
        {
          predLoc = location;
          location = location->next;
          moreToSearch = (location != NULL);
        }
        else
          moreToSearch = false;
    }

    // Prepare node for insertion
    newNode = new NodeType<ItemType>;
    newNode->info = item;
    // Insert node into list.
    if (predLoc == NULL)         // Insert as first
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
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
void SortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
    currentPos = NULL;
}
 
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is
//        current item.
{
    if (currentPos == NULL)
        currentPos = listData;
    item = currentPos->info;
    currentPos = currentPos->next;
}

template <class ItemType>
SortedType<ItemType>::~SortedType()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

template <class ItemType>
void SortedType<ItemType>::MergeLists(SortedType<ItemType> &other, SortedType<ItemType> &result)
{
    NodeType<ItemType> *ptr1;
    ptr1 = listData;
    NodeType<ItemType> *ptr2;
    ptr2 = other.listData;
    
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->info < ptr2->info)
        {
            result.InsertItem(ptr1->info);
            ptr1 = ptr1->next;
        }
        else
        {
            result.InsertItem(ptr2->info);
            ptr2 = ptr2->next;
        }
    }
    
    if(ptr1 == NULL)
    {
        result.InsertItem(ptr2->info);
        ptr2 = ptr2->next;
    }
    else
    {
        result.InsertItem(ptr1->info);
        ptr1 = ptr1->next;
    }
}

template <class ItemType>
void SortedType<ItemType>::DeleteItemA(ItemType item)
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* preLoc = NULL;
    
    while(location != NULL)
    {
        if(location->info == item)
        {
            if(location == listData)
            {
                listData = location->next;
                delete location;
                length--;
                break;
            }
            else
            {
                preLoc->next = location->next;
                delete location;
                length--;
                break;
            }
        }
        preLoc = location;
        location = location->next;
    }
}

template <class ItemType>
void SortedType<ItemType>::DeleteItemB(ItemType item)
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* preLoc = NULL;
    bool moreToSearch = (location != NULL);
    
    while(moreToSearch && location->info <= item)
    {
        if(location->info == item)
        {
            if(location == listData)
            {
                listData = location->next;
                delete location;
                length--;
                location = listData;
                moreToSearch = (location != NULL);
                continue;
            }
            else
            {
                preLoc->next = location->next;
                delete location;
                length--;
                location = preLoc->next;
                moreToSearch = (location != NULL);
                continue;
            }
        }
        else
        {
            preLoc = location;
            location = location->next;
        }
    }
}
