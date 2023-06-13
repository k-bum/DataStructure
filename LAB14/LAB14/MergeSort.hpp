#ifndef MergeSort_hpp
#define MergeSort_hpp
#include "Student.hpp"

void Merge (Student values[], int leftFirst, int leftLast,
     int rightFirst, int rightLast)
// Post: values[leftFirst]..values[leftLast] and
//       values[rightFirst]..values[rightLast] have been merged.
//       values[leftFirst]..values[rightLast] is now sorted.
{
    int arySize = rightLast - leftFirst + 1;
    Student* tempArray = new Student[arySize];
    int index = leftFirst;
    int saveFirst = leftFirst;
  
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        if (values[leftFirst].getName().compare(values[rightFirst].getName()) < 0)
        {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }

    while (leftFirst <= leftLast)
    // Copy remaining items from left half.
    {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }

    while (rightFirst <= rightLast)
    // Copy remaining items from right half.
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }

    for (index = saveFirst; index <= rightLast; index++)
        values[index] = tempArray[index];
    delete[] tempArray;
}

void MergeSort(Student values[], int first, int last)
// Post: The elements in values are sorted by key.
{
    if (first < last)
    {
        int middle = (first + last) / 2;
        MergeSort(values, first, middle);
        MergeSort(values, middle + 1, last);
        Merge(values, first, middle, middle + 1, last);
    }
}

#endif /* MergeSort_hpp */
