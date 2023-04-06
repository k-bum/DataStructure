#include <iostream>
using namespace std;

int BinarySearchA(int array[], int sizeOfArray, int value)
// 배열, 배열의 크기, 배열에서 찾고자 하는 값을 입력받아 찾고자 하는 값이 배열의 몇 번째에 있는지를 return
// 만일 배열에 찾는 대상이 없는 경우 -1을 return
{
    int midPoint = 0;
    int first = 0;
    int last = sizeOfArray - 1;
    while (first <= last)
    {
        midPoint = (first + last) / 2;
        if (value < array[midPoint])
            last = midPoint - 1;
        else if (value > array[midPoint])
            first = midPoint + 1;
        else
            return midPoint;
    }
    return -1;
}

int BinarySearchB(int array[], int sizeOfArray, int value)
// 배열, 배열의 크기, 배열에서 찾고자 하는 값을 입력받아 찾고자 하는 값이 배열의 몇 번째에 있는지를 return
// 만일 배열에 찾는 대상이 없는 경우 찾고자 하는 값보다 작거나 같은 값들 중에서 가장 큰 값을 return
{
    int midPoint = 0;
    int first = 0;
    int last = sizeOfArray - 1;
    while (first <= last)
    {
        midPoint = (first + last) / 2;
        if (value < array[midPoint])
            last = midPoint - 1;
        else if (value > array[midPoint])
            first = midPoint + 1;
        else
            return midPoint;
    }
    return array[last];
}

int BinarySearchC(int array[], int sizeOfArray, int value)
// 배열, 배열의 크기, 배열에서 찾고자 하는 값을 입력받아 찾고자 하는 값이 배열의 몇 번째에 있는지를 return
// 만일 배열에 찾는 대상이 없는 경우 찾고자 하는 값보다 크거나 같은 값들 중에서 가장 작은 값을 return
{
    int midPoint = 0;
    int first = 0;
    int last = sizeOfArray - 1;
    while (first <= last)
    {
        midPoint = (first + last) / 2;
        if (value < array[midPoint])
            last = midPoint - 1;
        else if (value > array[midPoint])
            first = midPoint + 1;
        else
            return midPoint;
    }
    return array[first];
}

int main()
{
    int list[10] = {2, 4, 5, 6, 8, 9, 10};
    int result = BinarySearchA(list, sizeof(list)/sizeof(list[0]), 11);
    cout << result << endl;
    result = BinarySearchB(list, sizeof(list)/sizeof(list[0]), 7);
    cout << result << endl;
    result = BinarySearchC(list, sizeof(list)/sizeof(list[0]), 7);
    cout << result << endl;
    return 0;
}
