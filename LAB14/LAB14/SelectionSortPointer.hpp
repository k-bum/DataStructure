#ifndef SelectionSortPointer_hpp
#define SelectionSortPointer_hpp

#include "Student.hpp"

int MinIndex(Student* values[], int startIndex, int endIndex)
{
    int indexOfMin = startIndex;
    for (int index = startIndex + 1; index <= endIndex; index++)
    {
        if (values[index]->getName().compare(values[indexOfMin]->getName()) < 0)
            indexOfMin = index;
    }
    return indexOfMin;
}

void SelectionSortPointer(Student* values[], int numValues)
{
    int endIndex = numValues - 1;
    for (int current = 0; current < endIndex; current++)
        Swap(values[current], values[MinIndex(values, current, endIndex)]);
}

#endif /* SelectionSortPointer_hpp */
