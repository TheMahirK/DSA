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


void rotate1(vector<vector<int>> &matrix)
{
    vector<vector<int>> result;
    int n = matrix.size();
    for(int i=0; i<n; i++)
    {
        vector<int> col;
        for(int j=0; j<n; j++)
        {
            col.push_back(matrix[j][i]);
        }
        reverse(col.begin(),col.end());
        result.push_back(col);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            matrix[i][j] = result[i][j];
        }
    }
}

void rotateMinus90(vector<vector<int>> &matrix)
{
    rotate1(matrix);
    rotate1(matrix);
    rotate1(matrix);
}

void rotate2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            result[j][n-i-1] = matrix[i][j];
        }
    }

    display(result);
}


void rotate3(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    display(matrix);
}

int main()
{
    vector<vector<int>> matrix = {{0,1,2},{3,4,5},{6,7,8}};
    display(matrix);

    // rotate90(matrix);

    // rotateMinus90(matrix);
    // display(matrix);

    rotate3(matrix);


    return 0;
}