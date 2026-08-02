#include <iostream>
using namespace std;

void display(vector<int> &series)
{
    for (auto x : series)
    {
        cout << x << ' ';
    }
    cout << endl;
}


int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int last = fibonacci(n - 1);
    int secondLast = fibonacci(n - 2);

    return last + secondLast;
}

int main()
{
    int n = 40;

    for (int i = 0; i <= n; i++)
    {
        cout << fibonacci(i) << ' ';
    }
    cout << endl;



    return 0;
}