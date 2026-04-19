#include <iostream>
#include <vector>
using namespace std;

void printF(int ind, int arr[], int size, vector<int> &subArr)
{
    if(ind == size)
    {
        for(auto num : subArr)
        {
            cout << num << ' ';
        }
        if(subArr.size() == 0)  cout << "{}";
        cout << endl;
        return;
    }

    // For taking element
    subArr.push_back(arr[ind]);
    printF(ind+1, arr, size, subArr);

    // For removing the already picked element
    subArr.pop_back();

    // For not taking the popped element (means taking next element)
    printF(ind+1, arr, size, subArr);
}

int main()
{
    int arr[] = {3,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector <int> subArr;

    printF(0, arr, size, subArr);


    return 0;
}