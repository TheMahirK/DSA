#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

vector<int> reArrangeArray1(vector<int> &arr)
{
    vector<int> result;
    vector<int> positives;
    vector<int> negatives;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            positives.push_back(arr[i]);
        }
        else
        {
            negatives.push_back(arr[i]);
        }
    }

    for(int i=0; i<n/2; i++)
    {
        result.push_back(positives[i]);
        result.push_back(negatives[i]);
    }
    return result;
}


vector<int> reArrangeArray2(vector<int> &arr)
{
    int n = arr.size();
    int countP = 0, countN = 1;

    vector<int> result(n,0);
    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            result[countP] = arr[i];
            countP += 2;
        }
        else
        {
            result[countN] = arr[i];
            countN += 2;
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {-1,2,3,-4,5,-6,-7,8};
    display(arr);

    vector<int> result = reArrangeArray2(arr);
    display(result);
}