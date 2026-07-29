#include <iostream>
using namespace std;

// Recursive Solution
int sumUptoN(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumUptoN(n - 1);
}

int main()
{
    int N = 10;

    cout << sumUptoN(N);

    return 0;
}