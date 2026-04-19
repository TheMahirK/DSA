#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printBoards(vector<vector<string>> &boards)
{
    int count = 1;
    for (auto &board : boards)
    {
        cout << "Sol : " << count << endl;
        for (auto row : board)
        {
            cout << row << endl;
        }
        count++;
        cout << endl;
    }
}

bool isSafe(int row, int col, vector<string> &board)
{
    int dupl_row = row;
    int dupl_col = col;

    // for upper left diagonal
    while(row >= 0 && col >= 0)
    {
        if(board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // to reset row & col
    row = dupl_row;
    col = dupl_col;

    // for left diagonal
    while(col >= 0)
    {
        if(board[row][col] == 'Q')
            return false;
        col--;
    }

    col = dupl_col;

    // for lower left diagonal
    while(row < board.size() && col >= 0)
    {
        if(board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;

}

void solve(int col, vector<vector<string>> &result, vector<string> &board)
{
    if(col == board.size())
    {
        result.push_back(board);
    }

    for(int row=0; row<board.size(); row++)
    {
        if(isSafe(row,col,board))
        {
            board[row][col] = 'Q';
            solve(col+1,result,board);
            board[row][col] = '.';
        }
    }
}


vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0; i<n; i++)
    {
        board[i] = s;
    }

    solve(0,result,board);
    return result;

}

int main()
{

    int n = 4;

    vector<vector<string>> result;
    result = solveNQueens(n);

    printBoards(result);


    return 0;
}