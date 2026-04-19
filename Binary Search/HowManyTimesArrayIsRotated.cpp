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

int countRotation(vector<int> &arr)
{
    int index = -1;
    int n = arr.size();
    int low = 0, high = n - 1;
    int mini = arr[0];

    while (low <= high)
    {
        int mid = (high + (low - high) / 2);

        if (arr[mid] < mini)
        {
            mini = arr[mid];
            index = mid;
        }

        if (arr[mid] > mini)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return index;
}

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    display(arr);

    int rotationNo = countRotation(arr);
    cout << "Array is rotated " << rotationNo << " times" << endl;

    return 0;
}