#include <iostream>
using namespace std;

// 피보나치 수열을 재귀함수로 계산할 경우 n이 작은 상황에서는 효율적이지만, n이 커질 경우 같은 n을 갖는 함수를 여러 번 반복해서 호출하기 때문에 비효울적이다.
int Fibonacci_recursive(int n)
{
    if(n == 0 || n == 1)
        return n;
    else
        return Fibonacci_recursive(n - 2) + Fibonacci_recursive(n - 1);
}

int Fibonacci_non_recursive(int n)
{
    int result = 0;
    int first = 0;
    int second = 1;
    for(int i = 2; i < n + 1; i++)
    {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

int main()
{
    cout << Fibonacci_recursive(10) << endl;
    cout << Fibonacci_non_recursive(10) << endl;
    
    return 0;
}

