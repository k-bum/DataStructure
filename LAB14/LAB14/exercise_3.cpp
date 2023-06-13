#include <iostream>
#include "Student.cpp"
#include "QuickSortPointer.hpp"
#include "MergeSortPointer.hpp"
#include "SelectionSortPointer.hpp"
#include "InsertionSortPointer.hpp"
#include "HeapSortPointer.hpp"
#include "BubbleSortPointer.hpp"
using namespace std;

int main()
{
    Student stu[100];
    stu[0].InitValue(2003200111, "이웅재", 3.0);
    stu[1].InitValue(2004200121, "권오준", 3.2);
    stu[2].InitValue(2005200132, "김진일", 2.7);
    Student* stuPtrs[3];
    
    for(int k = 0; k < 3; k++)
        stuPtrs[k] = &stu[k];
    //QuickSortPointer(stuPtrs, 0, 2);
    //MergeSortPointer(stuPtrs, 0, 2);
    //SelectionSortPointer(stuPtrs, 3);
    //InsertionSortPointer(stuPtrs, 3);
    //HeapSortPointer(stuPtrs, 3);
    BubbleSortPointer(stuPtrs, 3);
    PrintByPointer(cout, stuPtrs, 3);
}
