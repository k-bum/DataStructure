#include "PQSType.hpp"

PQSType::PQSType(int max)
{
    pqueue = PQType<ItemType>(max);
    timeStamp = 0;
}

PQSType::~PQSType()
{
    pqueue.~PQType();
}

// O(1)
void PQSType::Push(ItemType newItem)
{
    timeStamp++;
    pqueue.Enqueue(timeStamp, newItem);
}

// timeStamp가 높을수록 높은 우선순위(가장 큰 timeStamp를 갖는 원소가 최우선 순위)
// O(1)
void PQSType::Pop(ItemType& item)
{
    pqueue.Dequeue(item);
}

bool PQSType::IsFull() const
{
    return pqueue.IsFull();
}

bool PQSType::IsEmpty() const
{
    return pqueue.IsEmpty();
}
