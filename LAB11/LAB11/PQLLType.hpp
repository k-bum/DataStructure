#ifndef PQLLType_hpp
#define PQLLType_hpp
#include "SortedType.hpp"

class FullPQLL{};
class EmptyPQLL{};

template<class ItemType>
class PQLLType
{
public :
    PQLLType();
    ~PQLLType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
private :
    int length;
    SortedType<ItemType> linkedlist;
};

#endif /* PQLLType_hpp */
