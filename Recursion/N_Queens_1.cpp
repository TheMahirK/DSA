#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int row, int col, vector<string> &board)
{
    int duprow = row;
    int dupcol = col;

    // for upper left diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // to reset the row and col
    row = duprow;
    col = dupcol;

    // for left diagonal
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    col = dupcol;

    // for lower left diagonal
    while (col >= 0 && row <= board.size())
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}


void solve(int col, vector<string> &board, vector<vector<string>> &ans)
{
    if(col == board.size())
    {
        ans.push_back(board);
        return;
    }

    for(int row=0; row<board.size(); row++)
    {
        if (isSafe(row,col,board))
        {
            board[row][col] = 'Q';
            solve(col+1, board, ans);
            board[row][col] = '_';
        }
    }
}


vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'_');
    for(int i=0; i<n; i++)
    {
        board[i] = s;
    }

    solve(0,board,ans);

    return ans;
}


void printBoards(vector<vector<string>> &boards)
{
    int count = 1;
    for(auto &board : boards)
    {
        cout << "Sol : " << count << endl;
        for(auto row : board)
        {
            cout << row  << endl;
        }
        count++;
        cout << endl;
    }
}



int main()
{

    int n = 4;

    vector<vector<string>> result;
    result = solveNQueens(n);

    printBoards(result);

    return 0;
}