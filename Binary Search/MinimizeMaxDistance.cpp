/*

Program Name : Minimize the maximum distance between any two consecutive gas stations
Program Description : Given a sorted array which contains coordinates of n gas stations
and an integer k which indicates the number of new stations to be placed.

Our goal is to place the stations such that the maximum distance between two consecutive
gas stations is minimized and return that distance

*/

#include <iostream>
#include <queue>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

/*

1. Algorithm Used : Brute Force
   Time Complexity : O(N * k)
   Auxiliary Space Requirement : O(1)
   Intuition : For each section between two consecutive stations calculate the distance
   Also keep storing how many stations are placed in each section

   Calculate new section distance after allocation = distance/(how many allocated + 1)
   maximize this distance by using conditon
   after allocating increase the how many allocated counter

   After all stations are allocated , calculate new distances by same formula, the max of the
   new distances is the answer

*/

long double minMaxDistance1(vector<int> &arr, int k)
{
    int n = arr.size();

    if (n == 1)
    {
        return 0;
    }
    vector<int> howMany(n - 1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        long double maxSectionLen = -1;
        int maxInd = -1;

        for (int i = 0; i < n - 1; i++)
        {
            long double diff = arr[i + 1] - arr[i];
            long double currSectionLen = diff / (long double)(howMany[i] + 1);

            if (currSectionLen > maxSectionLen)
            {
                maxSectionLen = currSectionLen;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;

    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];

        long double sectionLen = diff / (long double)(howMany[i] + 1);

        if (sectionLen > maxAns)
        {
            maxAns = sectionLen;
        }
    }
    return maxAns;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(N logN) + O(k)
   Auxiliary Space Requirement : O(k)
   Intuition : Similar to brute force but instead of checking manually for max distance
   we use priority queue which keeps the max distance on the top.
   Rest approach is similar

*/

long double minMaxDistance2(vector<int> &arr, int k)
{
    int n = arr.size();

    if (n == 1)
    {
        return 0;
    }

    vector<int> howMany(n - 1, 0);

    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        pq.push({diff, i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp = pq.top();
        pq.pop();

        int sectionIndex = tp.second;

        howMany[sectionIndex]++;

        long double startDiff = arr[sectionIndex + 1] - arr[sectionIndex];

        long double newSecLen = startDiff / (long double)(howMany[sectionIndex] + 1);

        pq.push({newSecLen, sectionIndex});
    }
    return pq.top().first;
}

int main()
{
    vector<int> arr = {1, 13, 17, 23};

    // vector<int> arr = {13};

    int newStations = 5;

    int maxDist = minMaxDistance2(arr, newStations);
    cout << "Minimum of Maximum distance between two consecutive Gas" << 
    "stations after adding " << newStations << " new gas stations : " << maxDist << endl;

    return 0;
}