#include <iostream>
using namespace std;

// Print name N times using recursion
void fun1(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << "Mahir" << endl;
    fun1(n - 1);
}

// Print 1 to N using recursion
void fun2(int start, int n)
{
    if (start > n)
    {
        return;
    }
    cout << start << ' ';
    fun2(start + 1, n);
}

// Print N to 1 using recursion
void fun3(int n)
{
    if (n < 1)
    {
        return;
    }
    cout << n << ' ';
    fun3(n - 1);
}

// Print 1 to N using backtracking
void fun4(int n)
{
    if (n < 1)
    {
        return;
    }

    // Goes deep till 1 and then backtracks
    fun4(n - 1);
    cout << n << ' ';
}

// Print N to 1 using backtracking
void fun5(int start, int n)
{
    if (start > n)
    {
        return;
    }

    // Goes deep till N and then backtracks
    fun5(start + 1, n);
    cout << start << ' ';
}

int main()
{
    int n = 5;

    fun5(1, n);

    return 0;
}