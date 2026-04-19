#include <iostream>
#include <vector>
using namespace std;

void printF(int ind, int arr[], int size, vector<int> &subArr, int sum, int k)
{
    if(ind == size)
    {
        if(sum == k)
        {
            for(auto num : subArr)
            {
                cout << num << ' ';
            }
            cout << endl;
            
        }
        return;
    }

    // To pick the element 

    subArr.push_back(arr[ind]);
    sum = sum+arr[ind];
    printF(ind+1, arr, size, subArr, sum, k);

    // To remove the picked element
    subArr.pop_back();
    sum = sum-arr[ind];

    // To not pick the element
    printF(ind+1, arr, size, subArr, sum, k);


}

int main()
{
    int arr[] = {1,2,2,1,4,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    vector <int> subArr;
    int sum = 0;
    int k = 4;

    printF(0, arr, size, subArr, sum, k);

    return 0;
}