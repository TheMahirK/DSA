/*

Program Name : Binary Search in sorted matrix
Program Description : Given a sorted matrix (rows and cols both are sorted) and an element target
Find out wheter the target is present in the matrix or not


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

1. Algorithm Used : Brute force
   Time Complexity : O(M * N)
   Auxiliary Space Requirement : O(1)
   Intuition : Traverse through whole matrix and look for target

*/

bool search1(vector<vector<int>> &matrix, int target)
{
   int m = matrix.size();
   int n = matrix[0].size();

   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (matrix[i][j] == target)
         {
            return true;
         }
      }
   }
   return false;
}

bool binarySearch(vector<int> &arr, int target)
{
   int low = 0, high = arr.size() - 1;

   while (low <= high)
   {
      int mid = (low + (high - low) / 2);

      if (arr[mid] == target)
      {
         return true;
      }

      else if (arr[mid] < target)
      {
         low = mid + 1;
      }
      else
      {
         high = mid - 1;
      }
   }
   return false;
}

/*

2. Algorithm Used : Better
   Time Complexity : O(M * log[N])
   Auxiliary Space Requirement : O(1)
   Intuition : Traverse through all rows and perform binary search on each row

*/

bool search2(vector<vector<int>> &matrix, int target)
{
   int m = matrix.size();
   int n = matrix[0].size();

   for (int i = 0; i < m; i++)
   {
      bool result = binarySearch(matrix[i], target);

      if (result == true)
      {
         return result;
      }
   }
   return false;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(log[M] * log[N]) = O(log[M*N])
   Auxiliary Space Requirement : O(1)
   Intuition : Perform binary search for all rows , if hypotheticall target exists in that row ,
   find out yes or not using binary search.
   If the target is greater than last element of the row , it should exist in next rows
   Else it should exist in previous rows

*/

bool search3(vector<vector<int>> &matrix, int target)
{
   int m = matrix.size();
   int n = matrix[0].size();
   int low = 0, high = m - 1;

   while (low <= high)
   {
      int mid = (low + (high - low) / 2);

      if (matrix[mid][0] <= target && target <= matrix[mid][n - 1])
      {
         bool result = binarySearch(matrix[mid], target);

         if (result == true)
         {
            return true;
         }
         else
         {
            return false;
         }
      }

      else if (target > matrix[mid][n - 1])
      {
         low = mid + 1;
      }
      else
      {
         high = mid - 1;
      }
   }
   return false;
}

int main()
{

   vector<vector<int>> matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 8, 9}, {10, 10, 10, 11, 12}, {13, 13, 14, 15, 15}};
   display(matrix);

   int target = 5;

   bool result = search3(matrix, target);

   if (result)
   {
      cout << target << " Found";
   }
   else
   {
      cout << target << " Not Found";
   }

   return 0;
}