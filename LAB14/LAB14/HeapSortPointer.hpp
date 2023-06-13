#ifndef HeapSortPointer_hpp
#define HeapSortPointer_hpp
#include "Student.hpp"

void ReheapDown(Student* elements[], int root, int bottom)
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
        maxChild = leftChild;
    else
    {
        if (elements[leftChild]->getName().compare(elements[rightChild]->getName()) <= 0)
            maxChild = rightChild;
        else
            maxChild = leftChild;
    }
    if (elements[root]->getName().compare(elements[maxChild]->getName()) < 0)
    {
        Swap(elements[root], elements[maxChild]);
        ReheapDown(elements, maxChild, bottom);
    }
  }
}

void HeapSortPointer(Student* values[], int numValues)
{
  int index;
  for (index = numValues / 2 - 1; index >= 0; index--)
      ReheapDown(values, index, numValues-1);
  for (index = numValues-1; index >= 1; index--)
  {
      Swap(values[0], values[index]);
      ReheapDown(values, 0, index-1);
  }
}

#endif /* HeapSortPointer_hpp */
