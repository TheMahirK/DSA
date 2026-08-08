#include <iostream>
// #include <cmath>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

vector<int> findFactors(int n)
{
    vector<int> factors;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (n / i != i)
            {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

int main()
{
    int n = 36;

    vector<int> factors = findFactors(n);

    cout << "Factors of " << n << " are : ";
    display(factors);

    return 0;
}