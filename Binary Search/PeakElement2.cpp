/*

Program Name : Peak Element 2
Program Description : Given a 2D matrix of size MxN. In which no two adjacent elements are same
Meaning element in top , left , right and bottom are not equal to current element
And All elements outside the matrix are -1s
Find any one peak element in the matrix and return its {row , col}

A peak element in matrix is such that its greater than all its adjacent elements (top , left
, right and bottom)

*/

#include <iostream>
using namespace std;

void display(vector<vector<int>> &matrix)
{
    for (auto row : matrix)
    {
        for (auto x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

/*

1. Algorithm Used : Brute Force
   Time Complexity : O(M * N)
   Auxiliary Space Requirement : O(1)
   Intuition : Traverse through all elements and check for the peak element condition

*/

vector<int> peakElement2D1(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int top = -1, left = -1, right = -1, bottom = -1;
            if (i - 1 >= 0)
            {
                top = matrix[i - 1][j];
            }

            if (j - 1 >= 0)
            {
                left = matrix[i][j - 1];
            }

            if (i + 1 < m)
            {
                bottom = matrix[i + 1][j];
            }

            if (j + 1 < n)
            {
                right = matrix[i][j + 1];
            }
            int ele = matrix[i][j];
            if (ele > top && ele > left && ele > right && ele > bottom)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int getMaxEleRow(vector<vector<int>> &matrix, int col)
{
    int max = INT_MIN;
    int rowInd = -1;

    int m = matrix.size();

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][col] > max)
        {
            max = matrix[i][col];
            rowInd = i;
        }
    }
    return rowInd;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(N log [M])
   Auxiliary Space Requirement : O(1)
   Intuition : Use binary search on cols (or rows as per choice). Find the max element in that col
   (or row). This fulfills the condition of greater than top and bottom (or left and right).
   After this check for other two remaining adjacent elements. If condition is fulfilled we find the peak
   element.

   If curr element is less than left element than there is chance of a peak element in the left half
   Else peak element is in right half.

   Same can be done for top and bottom elements if we use rows for binary search

*/

vector<int> peakElement2D2(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);

        int left = -1, right = -1;

        int maxEleRow = getMaxEleRow(matrix, mid);

        if (mid - 1 >= 0)
        {
            left = matrix[maxEleRow][mid - 1];
        }
        if (mid + 1 < n)
        {
            right = matrix[maxEleRow][mid + 1];
        }

        int ele = matrix[maxEleRow][mid];

        if (ele > left && ele > right)
        {
            return {maxEleRow, mid};
        }

        if (ele < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 1, 1, 2, 1},
                                  {2, 4, 3, 2, 3, 2},
                                  {1, 7, 6, 0, 1, 3},
                                  {3, 6, 2, 3, 7, 2}};

    display(matrix);

    vector<int> peakEle = peakElement2D2(matrix);

    cout << peakEle[0] << ' ' << peakEle[1];

    return 0;
}