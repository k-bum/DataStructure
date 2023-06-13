#include <iostream>
#include "HeapSort.cpp"
using namespace std;

template <class  ItemType>
void  GetHeightSum(ItemType values[], int numValues)
{
    int  index, sum = 0;
    for (index = 0; index < numValues/2; index++)
        sum += GetHeight(values, index, numValues - 1);

    cout << "sum of heights = " << sum << endl;
}

template <class  ItemType >
int  GetHeight(ItemType values[], int start, int numValues)
{
    if (start >= (numValues + 1) / 2 || start > numValues)
        return 0;
    int l_height = GetHeight(values, start * 2 + 1, numValues);
    int r_height = GetHeight(values, start * 2 + 2, numValues);
    return (l_height > r_height) ? l_height + 1 : r_height + 1;
}

int main()
{
    int ary[9];

    ary[0] = 25;
    ary[1] = 17;
    ary[2] = 36;
    ary[3] = 2;
    ary[4] = 3;
    ary[5] = 100;
    ary[6] = 1;
    ary[7] = 19;
    ary[8] = 7;

    GetHeightSum(ary, 9);

    return 0;
}
