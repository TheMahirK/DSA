/*
Program Name : Merge Overlapping SubIntervals
Program Description : Given multiple intervals , merge the intervals such that merged interval
contain all elements of both the interval
Note : The intervals are given in random order
*/

#include <iostream>
using namespace std;

void displayIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    cout << '{';
    for (int i = 0; i < n; i++)
    {
        cout << '(';
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j];
            if (j == 0)
            {
                cout << ',';
            }
        }
        cout << ')';
        if (i < n - 1)
        {
            cout << ",";
        }
    }
    cout << '}';
    cout << endl;
}

/*
1. Algorithm Used : Brute Force
   Time Complexity : O(N log N) + O(2N)
   Auxiliary Space Requirement : O(N)
   Intuition : Sort the intervals and start iterating over them and merge overlapping ones
*/

vector<vector<int>> mergeIntervals1(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (!result.empty() && end <= result.back()[1])
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }

            else
            {
                break;
            }
        }

        result.push_back({start, end});
    }

    return result;
}

/*
1. Algorithm Used : Better
   Time Complexity : O(N log N) + O(N)
   Auxiliary Space Requirement : O(N)
   Intuition : Sort the intervals and start iterating over them and merge overlapping ones
*/

vector<vector<int>> mergeIntervals2(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        if (result.empty())
        {
            result.push_back(intervals[i]);
        }
        else
        {
            if (intervals[i][0] <= result.back()[1])
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
    }

    return result;
}

int main()
{

    vector<vector<int>> intervals = {{1,4},{4,8},{8,12},{0,24}};
    displayIntervals(intervals);

    vector<vector<int>> mergedIntervals = mergeIntervals2(intervals);
    displayIntervals(mergedIntervals);

    return 0;
}