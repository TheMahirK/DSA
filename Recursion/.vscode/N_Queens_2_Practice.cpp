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


void solve(int col, vector<vector<string>> &result, vector<int> &leftRow,
vector<int> &lowerDiagonal, vector<int> &upperDiagonal, vector<string> &board)
{
    if(col == board.size())
    {
        result.push_back(board);
    }

    for(int row=0; row<board.size(); row++)
    {
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && 
            upperDiagonal[board.size()-1+col-row] == 0)
            {
                // to add queen
                board[row][col] = 'Q';

                // to write in hashtables
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[board.size()-1+col-row] = 1;
                
                solve(col+1,result,leftRow,lowerDiagonal,upperDiagonal,board);

                // to remove the added queen
                board[row][col] = '.';


                // to undo the hashtables
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[board.size()-1+col-row] = 0;               

            }
    }

}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<int> leftRow(n,0);
    vector<int> lowerDiagonal (2*n-1, 0);
    vector<int> upperDiagonal (2*n-1, 0);

    vector<string> board(n);

    string s(n,'.');
    for(int i=0; i<n; i++)
    {
        board[i] = s;
    }

    solve(0,result,leftRow,lowerDiagonal,upperDiagonal,board);

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