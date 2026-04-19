#include <iostream>
using namespace std;

void display(vector<vector<int>> &arr)
{
    for(auto row : arr)
    {
        for(auto x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

long long nCr(int n, int r)
{
    long long res = 1;
    for(int i=0; i<r; i++)
    {
        res *= (n-i);
        res = res/(i+1);
    }
    return res;
}

vector<vector<int>> pascalsTriangle(int numRows)
{
    vector<vector<int>> result;
    for(int n=1; n<=numRows; n++)
    {
        vector<int> row;
        for(int r=1; r<=n; r++)
        {
            row.push_back(nCr(n-1,r-1));
        }
        result.push_back(row);
    }
    return result;
}

int main()
{

    int numRows = 5;

    vector<vector<int>> triangle = pascalsTriangle(numRows);
    display(triangle);

    return 0;
}