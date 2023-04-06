#include "Unsorted.hpp"
// Implementation file for Unsorted.h
#include <iostream>
#include "Unsorted.hpp"
using namespace std;

UnsortedType::UnsortedType()
{
  length = 0;
}

bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
  return length;
}

void UnsortedType::RetrieveItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    int location = 0;
    found = false;
    
    moreToSearch = (location < length);
    
    while (moreToSearch && !found) {
        switch (item.ComparedTo(info[location]))
        {
            case LESS    :
            case GREATER : location++;
                           moreToSearch = (location < length);
                           break;
            case EQUAL   : found = true;
                           item = info[location];
                           break;
                
        }
    }
}

void UnsortedType::InsertItem(ItemType item)
{
    info[length] = item;
    length++;
}

void UnsortedType::DeleteItem(ItemType item)
{
    int location = 0;
    
    while (item.ComparedTo(info[location]) != EQUAL)
        location++;
    info[location] = info[length - 1];
    length--;
}

void UnsortedType::ResetList()
{
    currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType &item)
{
    currentPos++;
    item = info[currentPos];
}

void UnsortedType::DeleteItem_a(ItemType item) {
  bool deleted = false;
  for(int i = 0; i < length && !deleted; i ++) {
    if(item.ComparedTo(info[i]) == EQUAL) {
      info[i] = info[i-1];
      length--;
      deleted = true;
    }
  }
}

void UnsortedType::DeleteItem_c(ItemType item) {
  int i = 0;
  while(i < length) {
    if(item.ComparedTo(info[i]) == EQUAL) {
      info[i] = info[length-1];
      length--;
    }
    else
      i++;
  }
}
