
/*

Program Name : Aggresive cows
Program Description : Given an array which represents the position of different stalls
Integer cows : This represents the number of aggressive cows
Our goal is to find the maximum of minimum distance between any two cows
i.e. Place the cows such that the closest two cows are still far apart as possible

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

bool isPossible(vector<int> &arr, int distance, int cows)
{
    int n = arr.size();
    int countCows = 1;
    int lastCowPos = arr[0];

    for (int i = 1; i < n; i++)
    {
        int currDist = arr[i] - lastCowPos;
        if (currDist >= distance)
        {
            countCows++;
            lastCowPos = arr[i];
        }

        if (countCows >= cows)
        {
            return true;
        }
    }
    return false;
}

/*

1. Algorithm Used : Brute Force
   Time Complexity : O(O(NlogN) + [max(arr)-min(arr)]*N), N = arr.size() or No. of stalls
   Auxiliary Space Requirement : O(1)
   Intuition : The maximum distance between any two stalls is max(arr)-min(arr)
   and the minimum distance between any two stalls is 1
   Try every possible distance in this range minimzing the distance between stalls/cows
   Whenever we reach at a distance where the distance further cannot be increased we find the answer


*/

int minDistance1(vector<int> &arr, int cows)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();

    int maxDist = arr[n - 1] - arr[0];

    for (int i = 1; i <= maxDist; i++)
    {
        if (isPossible(arr, i, cows))
        {
            continue;
        }
        else
        {
            return i - 1;
        }
    }
    return maxDist;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(NlogN + O(log(max(arr)-min(arr)) * N))
   Auxiliary Space Requirement : O(1)
   Intuition :  It is similar to above but we use binary search to check possibility condition
   If some distance is possibly , we try for farther distance
   If some distance is not possible , we try closer distance

*/

int minDistance2(vector<int> &arr, int cows)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    // cout << "Stalls : ";
    // display(arr);

    int maxDist = arr[n - 1] - arr[0];

    int low = 1, high = maxDist;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);

        // Try farther distance
        if (isPossible(arr, mid, cows))
        {
            low = mid + 1;
        }

        // Try closer distance
        else
        {
            high = mid - 1;
        }
    }
    // Maximum possible distance
    return high;
}

int main()
{
    vector<int> arr = {0, 3, 4, 10, 9, 7};
    display(arr);

    int cows = 4;

    int minDistance = minDistance2(arr, cows);

    display(arr);

    cout << "No. of cows : " << cows << endl;
    cout << "Largest minimum distance between cows is: " << minDistance;

    return 0;
}