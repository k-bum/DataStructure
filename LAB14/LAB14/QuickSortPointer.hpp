#ifndef QuickSortPointer_hpp
#define QuickSortPointer_hpp
#include "Student.hpp"

void Split(Student* values[], int first, int last, int& splitPoint)
{
    Student* splitVal = values[first];
    int saveFirst = first;
    bool onCorrectSide;

    first++;
    do
    {
        onCorrectSide = true;
        while (onCorrectSide)         // Move first toward last.
            if (splitVal->getName().compare(values[first]->getName()) < 0)
                onCorrectSide = false;
            else
            {
                first++;
                onCorrectSide = (first <= last);
            }

        onCorrectSide = (first <= last);
        while (onCorrectSide)             // Move last toward first.
            if (splitVal->getName().compare(values[first]->getName()) > 0)
                onCorrectSide = false;
            else
            {
                last--;
                onCorrectSide = (first <= last);
            }

        if (first < last)
        {
            Swap(values[first], values[last]);
            first++;
            last--;
            }
        }
        while (first <= last);
    
        splitPoint = last;
        Swap(values[saveFirst], values[splitPoint]);
}


template<class ItemType>
void QuickSortPointer(ItemType* values[], int first, int last)
{
    if (first < last)
    {
        int splitPoint;

        Split(values, first, last, splitPoint);
        QuickSortPointer(values, first, splitPoint - 1);
        QuickSortPointer(values, splitPoint + 1, last);
    }
}

#endif /* TagSort_hpp */
