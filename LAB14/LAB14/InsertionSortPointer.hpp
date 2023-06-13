#ifndef InsertionSortPointer_hpp
#define InsertionSortPointer_hpp

#include "Student.hpp"

void InsertItem(Student* values[], int startIndex, int endIndex)
{
    bool finished = false;
    int current = endIndex;
    bool moreToSearch = (current != startIndex);

    while (moreToSearch && !finished)
    {
        if (values[current]->getName().compare(values[current - 1]->getName()) < 0)
        {
            Swap(values[current], values[current - 1]);
            current--;
            moreToSearch = (current != startIndex);
        }
        else
            finished = true;
    }
}

void InsertionSortPointer(Student* values[], int numValues)
{
    for (int count = 0; count < numValues; count++)
        InsertItem(values, 0, count);
}


#endif /* InsertionSortPointer_hpp */
