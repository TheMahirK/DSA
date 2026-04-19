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

void solve(int col, vector<string> &board, vector<vector<string>> &ans,
           vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
{
    if (col == board.size())
    {
        ans.push_back(board);
    }
    for (int row = 0; row < board.size(); row++)
    {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0
             && upperDiagonal[board.size() - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[board.size() - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[board.size() - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    vector<int> leftRow(n, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal);
    return ans;
}

int main()
{

    int n = 4;

    vector<vector<string>> result;
    result = solveNQueens(n);

    printBoards(result);

    return 0;
}