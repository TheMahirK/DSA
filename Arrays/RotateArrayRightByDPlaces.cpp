/*

Program Name : Sort Colors
Program Description : Sort array containing 0s, 1s and 2s

1. Algorithm Used : Brute Force
   Time Complexity : O(N log N)
   Auxiliary Space Requirement : O(N)

2. Algorithm Used : Better
   Time Complexity : O(2N)
   Auxiliary Space Requirement : O(1)

3. Algorithm Used : Optimal - Dutch National Flag Algorithm
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)

*/

#include <iostream>
using namespace std;

void display(vector<int> &v)
{
    for(auto x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void rightRotateByDPlaces(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d%n;
    if(d == 0)
    {
        return;
    }
    reverse(arr.begin(), arr.begin()+n-d);
    reverse(arr.begin()+n-d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{

    vector<int> arr = {1,2,3,4,5,6,7};
    display(arr);

    rightRotateByDPlaces(arr, 8);
    display(arr);

    return 0;
}