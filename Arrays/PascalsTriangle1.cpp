/*

Program Name : Pascal's Triangle
Program Description : Given row number and column number , print the element at row and column of
Pascal's Triangle

*/
#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    int result = 1;
    for(int i=n; i>=1; i--)
    {
        result *= i;
    }
    return result;
}

int nCr1(int n, int r)
{
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int nCr2(int n, int r)
{
    long long res = 1;
    for(int i=0; i<r; i++)
    {
        res *= (n-i);
        res = res/(i+1);
    }
    return res;
}

/*
1. Algorithm Used : Brute Force
   Time Complexity : O(2N)
   Auxiliary Space Requirement : O(1)
   Intuition : Let row = n, and col = r, the nth row and rth col element is given by (n-1) C (r-1)
*/

int pascalsTriangle1(int row, int col)
{
    return nCr1(row-1, col-1);
}

/*
1. Algorithm Used : Better
   Time Complexity : O(col)
   Auxiliary Space Requirement : O(1)
   Intuition : Let row = n, and col = r, the nth row and rth col element is given by (n-1) C (r-1)
   In this we use better version of nCr function
*/

int pascalsTriangle2(int row, int col)
{
    return nCr2(row-1, col-1);
}


void printPascalsTriangleRow(int row)
{
    for(int c=1; c<=row; c++)
    {
        cout << nCr2(row-1, c-1) << ' ';
    }
}



// void printPascalsTriangle(int n)
// {
//     for(int i=1; i<=n; i++)
//     {
//         printPascalsTriangleRow(i);
//         cout << endl;
//     }
// }

int main()
{
    int row = 8, col = 4;
    // int n = 20, r = 5;
    // cout << pascalsTriangle1(row, col);

    // printPascalsTriangleRow(5);

    return 0;
}