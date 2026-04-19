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

void display(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> result;

    int top = 0, left = 0;
    int bottom = m-1, right = n-1;
    while(top <= bottom && left <= right)
    {    for(int i=left; i<=right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top; i<=bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom)
        {
            for(int i=right; i>=left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left <= right)
        {
            for(int i=bottom; i>=top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}


int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
    display(matrix);

    vector<int> result = spiralOrder(matrix);
    display(result);

    return 0;
}