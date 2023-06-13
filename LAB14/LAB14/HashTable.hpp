#ifndef HashTable_hpp
#define HashTable_hpp
#include "Student.hpp"
#include <string>
using namespace std;

const int MAX_ITEMS = 20000;

template<class ItemType>
class HashTable
{
public :
    HashTable();
    HashTable(ItemType emptyKey);
    int Hash(string key) const;
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    
private :
    ItemType info[MAX_ITEMS];
    ItemType emptyItem;
    int length;
};

template <class ItemType>
HashTable<ItemType>::HashTable(ItemType item)
{
    length = 0;
    emptyItem = item.EmptyKey();
    for (int i = 0; i < MAX_ITEMS; i++)
        info[i] = emptyItem;
}

int getIntFromString(string key)
{
    int sum = 0;
    int len = static_cast<int>(key.length());
    if (len % 2 == 1) len++;
    for (int j = 0; j < len; j += 2)
        sum = (sum + 100 * key[j] + key[j + 1]) % 19937;
    return sum;
}

template <class ItemType>
int HashTable<ItemType>::Hash(string key) const
{
    return (getIntFromString(key) % MAX_ITEMS);
}

template<class ItemType>
void HashTable<ItemType>::InsertItem(ItemType item)
{
    int location;
    location = Hash(item.Key());
    while (info[location] != emptyItem)
        location = (location + 1) % MAX_ITEMS;
    info[location] = item;
    length++;
}

template<class ItemType>
void HashTable<ItemType>::RetrieveItem(ItemType &item, bool &found)
{
    int location;
    int startLoc;
    bool moreToSearch = true;

    startLoc = Hash(item.Key());
    location = startLoc;
    do
    {
        if (info[location] == item || info[location] == emptyItem)
            moreToSearch = false;
        else
            location = (location + 1) % MAX_ITEMS;
    } while (moreToSearch);
    
    found = (info[location].Key().compare(item.Key()) == 0);

    if (found)
        item = info[location];
}

#endif /* HashTable_hpp */
