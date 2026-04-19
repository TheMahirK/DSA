/*

Program Name : Maximum Product Subarray
Program Description : Given an integer array nums, find a subarray that
has the largest product, and return the product.
Note that the product of an array with a single element is the value of that element.

*/

#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

/*
1. Algorithm Used : Brute Force
   Time Complexity : O(N^3)
   Auxiliary Space Requirement : O(1)
   Intuition : Try all the possible combinations and check
*/

int maxProduct1(vector<int> &arr)
{
    int maxProduct = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currProduct = 1;
            for (int k = i; k <= j; k++)
            {
                currProduct *= arr[k];
            }

            if (currProduct > maxProduct)
            {
                maxProduct = currProduct;
            }
        }
    }

    return maxProduct;
}

/*
2. Algorithm Used : Better
   Time Complexity : O(N^2)
   Auxiliary Space Requirement : O(1)
   Intuition : Same as brute force but without re-iterating for product
*/

int maxProduct2(vector<int> &arr)
{
    int maxProduct = arr[0];
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int currProduct = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            currProduct *= arr[j];

            if (currProduct > maxProduct)
            {
                maxProduct = currProduct;
            }
        }
    }
    return maxProduct;
}

/*
3. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : Use two pointer product approach (prefix and suffix), in case of zero
   reset the prefix or suffix to 1
*/

int maxProduct3(vector<int> &arr)
{
    int maxProduct = INT_MIN;
    int n = arr.size();
    int prefix = 1;
    int suffix = 1;

    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
        {
            prefix = 1;
        }
        if (suffix == 0)
        {
            suffix = 1;
        }

        prefix *= arr[i];
        suffix *= arr[n - i - 1];

        if (prefix > maxProduct || suffix > maxProduct)
        {
            maxProduct = max(maxProduct, max(prefix, suffix));
        }
    }

    return maxProduct;
}

int main()
{
    vector<int> arr = {2, 3, -2, 4};

    display(arr);

    int maxProduct = maxProduct3(arr);
    cout << "Maximum Product : " << maxProduct;

    return 0;
}