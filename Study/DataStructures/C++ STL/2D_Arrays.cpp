/*
    Note: While passing a 2D matrix to a function, it must be ensured to pass the col parameter without fail.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // C Style array
    // Creating a 2D matrix. Rows and cols must be defined at compile time
    const int rows = 3, cols = 4;
    int arr[rows][cols] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // Access elements
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // STL array
    array<array<int, cols>, rows> arr1 = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}};

    // Access elements
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr1[i][j] << " ";
        cout << endl;
    }

    return 0;
}