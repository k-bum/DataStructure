#ifndef Heap_hpp
#define Heap_hpp

template <class ItemType>
void swap(ItemType& one, ItemType& two);

template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    ItemType* elements;   // Array to be allocated dynamically
    ItemType* info;
    int numElements;
};

template <class ItemType>
void Swap(ItemType& one, ItemType& two)
{
    ItemType temp;
    temp = one;
    one = two;
    two = temp;
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  int parent;
  
  if (bottom > root)
  {
      parent = (bottom - 1) / 2;
      if (elements[parent] < elements[bottom])
      {
          Swap(elements[parent], elements[bottom]);
          Swap(info[parent], info[bottom]);
          ReheapUp(root, parent);
      }
  }
}

template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
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
      if (elements[leftChild] <= elements[rightChild])
          maxChild = rightChild;
      else
          maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
        Swap(elements[root], elements[maxChild]);
        Swap(info[root], info[maxChild]);
        ReheapDown(maxChild, bottom);
    }
  }
}

/*
//O(log(N))
template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
    int parent;
    bool reheaped = false;
    
    while(bottom > root && !reheaped)
    {
        parent = (bottom - 1) / 2;
        
        if(elements[parent] < elements[bottom])
        {
            Swap(elements[parent], elements[bottom]);
            bottom = parent;
        }
        else
            reheaped = true;
    }
}

//O(log(N))
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
    int maxChild, leftChild, rightChild;
    bool reheaped = false;
    
    leftChild = root * 2 + 1;
    
    while(leftChild <= bottom && !reheaped)
    {
        if(leftChild == bottom)
            maxChild = bottom;
        else
        {
            rightChild = root * 2 + 2;
            maxChild = (elements[leftChild] <= elements[rightChild] ? rightChild : leftChild);
        }
        
        if(elements[root] < elements[maxChild])
        {
            Swap(elements[root], elements[maxChild]);
            root = maxChild;
            leftChild = root * 2 + 1;
        }
        
        else
            reheaped = true;
    }
}
*/
#endif /* Heap_hpp */
