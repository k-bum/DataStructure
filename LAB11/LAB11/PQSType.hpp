#ifndef PQSType_hpp
#define PQSType_hpp
#include "PQType.hpp"

typedef int ItemType;

class PQSType
{
public:
    PQSType(int max);
    ~PQSType();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(ItemType newItem);
    void Pop(ItemType& item);
    
private:
    int timeStamp;
    PQType<ItemType> pqueue;
};

#endif /* PQSType_hpp */
