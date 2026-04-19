#include <iostream>
#include <vector>
using namespace std;

bool printF(int ind, int arr[], int size, vector<int> &subArr, int sum, int k)
{
    if(ind == size)
    {
        // condition satisfied
        if(sum == k)
        {
            for(auto num : subArr)
            {
                cout << num << ' ';
            }
            cout << endl;
            return true;
            
        }
        // condition not satisfied
        return false;
    }

    // To pick the element 

    subArr.push_back(arr[ind]);
    sum = sum+arr[ind];
    if(printF(ind+1, arr, size, subArr, sum, k) == true)
    {
        return true;
    }

    // To remove the picked element
    subArr.pop_back();
    sum = sum-arr[ind];

    // To not pick the element
    if(printF(ind+1, arr, size, subArr, sum, k) == true)
    {
        return true;
    }

    return false;


}

int main()
{
    int arr[] = {1,2,3,4,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    vector <int> subArr;
    int sum = 0;
    int k = 4;

    printF(0, arr, size, subArr, sum, k);

    return 0;
}