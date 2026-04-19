#include <iostream>
using namespace std;

void display(vector<vector<int>> &matrix)
{
    for(auto row : matrix)
    {
        for(auto x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void transpose(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    
    for(int i=0; i<n;)
    {
        for(int j=i+1; j<n;)
        {
            swap(matrix[i][j], matrix[j][i]);
            j++;
        }
        i++;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    display(matrix);

    transpose(matrix);
    display(matrix);

    return 0;
}