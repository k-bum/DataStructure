#ifndef BubbleSortPointer_hpp
#define BubbleSortPointer_hpp
#include "Student.hpp"

void BubbleUp(Student* values[], int startIndex, int endIndex)
{
  for (int index = endIndex; index > startIndex; index--)
    if (values[index]->getName().compare(values[index - 1]->getName()) < 0)
      Swap(values[index], values[index-1]);
}

void BubbleSortPointer(Student* values[], int numValues)
{
  int current = 0;

  while (current < numValues - 1)
  {
    BubbleUp(values, current, numValues-1);
    current++;
  }
}

#endif /* BubbleSortPointer_hpp */
