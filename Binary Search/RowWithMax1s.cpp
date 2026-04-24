/*

Program Name : Row with maximum 1s
Program Description : Given a 2D matrix , every row of matrix is sorted and have 0s and 1s only
Find the row with maximum number of 1s present (0 based indexing)

Note : In case of multiple rows have maximum number of 1s, return the row with lowest index which
contain maximum number of 1s


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
}

/*

1. Algorithm Used : Brute force
   Time Complexity : O(n*m)
   Auxiliary Space Requirement : O(1)
   Intuition : count 1s for every row , and keep updating max and index together

*/

int rowWithMaxOnes1(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int ind = 0;
    int max = 0;

    for (int i = 0; i < m; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                count = n - j;
                break;
            }
        }
        if (count > max)
        {
            max = count;
            ind = i;
        }
    }
    return ind;
}

/*

2. Algorithm Used : Better/Optimal
   Time Complexity : O(M * log N), M = no. of rows, N = no. of cols.
   Auxiliary Space Requirement : O(1)
   Intuition : Use upper bound for 0 , lower bound for 1 or binary search for first occurence of 1
   Here I used upper bound for 0
   Upper bound for 0 gives number of zeroes in that row, number of 1s = no. of zeroes - no. of cols.

*/

int rowWithMaxOnes2(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int ind = 0;
    int max = 0;
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        int upperBound = upper_bound(matrix[i].begin(), matrix[i].end(), 0) - matrix[i].begin();
        int countOnes = n - upperBound;

        if (countOnes > max)
        {
            max = countOnes;
            ind = i;
        }
    }
    return ind;
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 1, 1, 1}, {0, 0, 0, 1, 1}, {0, 1, 1, 1, 1}, {0, 0, 1, 1, 1}};

    display(matrix);

    int maxOnesRow = rowWithMaxOnes2(matrix);

    cout << "The row with max 1s is : " << maxOnesRow;

    return 0;
}