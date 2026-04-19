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

int singleElement(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
    {
        return arr[0];
    }

    if (arr[0] != arr[1])
    {
        return arr[0];
    }

    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        else
        {
            if (arr[mid] == arr[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return arr[low];
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6,6};
    display(arr);

    int singleEle = singleElement(arr);

    cout << "Single Element : " << singleEle << endl;

    return 0;
}