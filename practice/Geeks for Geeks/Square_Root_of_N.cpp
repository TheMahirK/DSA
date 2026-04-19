#include <iostream>
using namespace std;

int floorSquareRoot(int n)
{
    int low = 1;
    int high = n;
    int result = 1;
    while(low <= high)
    {
        int mid = (low+high)/2;

        if(mid*mid <= n)
        {
            result = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return result;
}

int main()
{
    int n = 76;
    int sqrt = floorSquareRoot(n);
    cout << sqrt;

    return 0;
}