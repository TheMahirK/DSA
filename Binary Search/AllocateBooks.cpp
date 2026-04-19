/*

Program Name : Allocate Books
Program Description : Given an array representing no. of pages in ith book
integer student : no. of students among which we have to distribute all books
The books must be assigned in order only and in complete form.
Each student must be assigned at least one book
It may be possible that there are more books than students. In that case some
students might be assigned more than one book.
Our goal is to distribute the books in such a way that
the student who gets the most pages has as few pages as possible.


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

int countStudents(vector<int> &arr, int pages)
{
    int studentCount = 1;
    int pagesCount = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (pagesCount + arr[i] <= pages)
        {
            pagesCount += arr[i];
        }
        else
        {
            studentCount++;
            pagesCount = arr[i];
        }
    }
    return studentCount;
}

/*

1. Algorithm Used : Brute Force (Linear Search)
   Time Complexity : O([sum(arr) - max(arr)]*N)
   Auxiliary Space Requirement : O(1)
   Intuition : The range of pages for a student is max(arr) <= pages <= sum(arr)
   We check that if it is possible to give all students pages less than or equal to
   every number in range. The first answer we find where it is possible is the minimum
   pages

*/

int minPages1(vector<int> &arr, int students)
{
    int maxEle = arr[0];
    int sum = arr[0];
    int n = arr.size();

    // Impossible condition
    if (students > n)
        return -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxEle)
        {
            maxEle = arr[i];
        }
        sum += arr[i];
    }

    for (int pages = maxEle; pages <= sum; pages++)
    {
        int studentsCount = countStudents(arr, pages);
        if (studentsCount <= students)
        {
            return pages;
        }
    }
    return -1;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(log[sum(arr) - max(arr)]*N)
   Auxiliary Space Requirement : O(1)
   Intuition : The solution is similar to brute force but we use binary search
   to narrow down the range.

*/

int minPages2(vector<int> &arr, int students)
{
    int maxEle = arr[0];
    int sum = arr[0];
    int n = arr.size();

    // Impossible condition
    if (students > n)
        return -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxEle)
        {
            maxEle = arr[i];
        }
        sum += arr[i];
    }

    int low = maxEle, high = sum;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);

        int noOfStudents = countStudents(arr, mid);

        // less pages , more students so increase pages
        if (noOfStudents > students)
        {
            low = mid + 1;
        }

        // more pages , less students, so decrease pages
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    vector<int> arr = {15, 10, 19, 10, 5, 18, 7};
    display(arr);

    int students = 5;

    int minPages = minPages2(arr, students);

    cout << "The minimum of Maximum pages a student will get : " << minPages;

    return 0;
}