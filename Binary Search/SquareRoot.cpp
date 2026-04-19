#include <iostream>
using namespace std;

int squareRoot(int x)
{
    if (x == 1)
    {
        return x;
    }
    int low = 0, high = x / 2;

    while (low <= high)
    {
        long long mid = (low + (high - low) / 2);
        long long sqr = (mid * mid);

        if (sqr <= x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int x = 1024;

    cout << "Square root of " << x << " is = " << squareRoot(x) << endl;

    return 0;
}