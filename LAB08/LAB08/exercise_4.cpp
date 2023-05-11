#include <iostream>
using namespace std;

#define MAX_ROWS 10
#define MAX_COLS 10

int NumPaths(int row, int col, int n)
{
    if((row == n) || (col == n))
        return 1;
    else
        return NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
}

int mat[MAX_ROWS][MAX_COLS];
int NumPaths_C(int row, int col, int n)
{
    if(mat[row][col] == -1)
    {
        if((row == n) || (col == n))
            return 1;
        else
            mat[row][col] = NumPaths_C(row + 1, col, n) + NumPaths_C(row, col + 1, n);
    }
    return mat[row][col];
}

int main() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++)
            mat[i][j] = -1;
    }

    cout << NumPaths_C(2, 2, 3) << endl;

    return 0;
}
