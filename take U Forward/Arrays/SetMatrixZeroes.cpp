#include <iostream>
using namespace std;

void display(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
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

void setRowZeroes(vector<vector<int>> &arr, int i)
{
    int m = arr[i].size();
    for(int j=0; j<m; j++)
    {
        if(arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}

void setColumnZeroes(vector<vector<int>> &arr, int j)
{
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        if(arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}
void setMatrixZeroes1(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j] == 0)
            {
                setRowZeroes(arr, i);
                setColumnZeroes(arr, j);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }

}

void display2(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void setMatrixZeroes2(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();
    vector<int> row(m , 0);
    vector<int> col(n, 0);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] == 0)
            {
               row[i] = 1;
               col[j] = 1;
            }
        }
    }
    display2(row);
    display2(col);
    cout << endl;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(row[i] == 1 || col[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
    

}

void setMatrixZeroes3(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();

    // ith row -> arr[.][0]
    // jth col -> arr[0][j]

    int col0 = 1;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] == 0)
            {
                // mark ith row

                arr[i][0] = 0;

                // mark jth col
                if(j != 0)
                {
                    arr[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(arr[i][j] != 0)
                {
                    if(arr[i][0] == 0 || arr[0][j] == 0)
                    {
                        arr[i][j] = 0;
                    }
                }
            }
        }
        if(arr[0][0] == 0)
        {
            for(int j=0; j<n; j++)
            {
                arr[0][j] = 0;
            }
        }
        if(col0 == 0)
        {
            for(int i=0; i<m; i++)
            {
                arr[i][0] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1,1,1,1},{1,0,1,1},{1,1,0,1},{0,1,1,1},{1,1,1,0}};
    display(arr);

    // setMatrixZeroes1(arr);
    // display(arr);

    // setMatrixZeroes2(arr);
    // display(arr);

    setMatrixZeroes3(arr);
    display(arr);

}