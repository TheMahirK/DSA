#include <iostream>
#include <vector>
using namespace std;

int printF(int ind, int arr[], int size, int sum, int k)
{
    if(sum > k) return 0;
    if(ind == size)
    {
        // condition satisfied
        if(sum == k)
        {
            return 1;
            
        }
        // condition not satisfied
        return 0;
    }

    // To pick the element 
    sum = sum+arr[ind];
    int L = printF(ind+1, arr, size, sum, k);


    // To remove the picked element
    sum = sum-arr[ind];

    // To not pick the element
    int R = printF(ind+1, arr, size, sum, k);

    return L+R;


}

int main()
{
    int arr[] = {2,1,2,3,4,2};
    int size = sizeof(arr)/sizeof(arr[0]);


    int sum = 0;
    int k = 4;

    cout << printF(0, arr, size, sum, k);

    return 0;
}