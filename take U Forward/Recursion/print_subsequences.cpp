#include <iostream>
#include <vector>
using namespace std;
void printF(int index, int arr[], int n,
     vector<int> &subArr,int &count)
{
    if(index == n)
    {
        count++;
        cout << count << ':' << ' ';

        for(auto num : subArr)
        {
            cout << num << ' ';
        }
        if(subArr.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }

    subArr.push_back(arr[index]);

    printF(index+1, arr, n, subArr,count);

    subArr.pop_back();

    printF(index+1, arr, n, subArr,count);

}

int main()
{
    int arr[] = {0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> subArr;
    int count = 0;
    printF(0,arr,n,subArr,count);


    return 0;
}