#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n)
{
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 'Q') return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q') return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 'Q') return false;

    return true;
}

void solve(int row, vector<string>& board, int n, vector<vector<string>>& solutions)
{
    if (row == n)
    {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(row + 1, board, n, solutions);
            board[row][col] = '.';
        }
    }
}

void nQueens(int n)
{
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    
    solve(0, board, n, solutions);

    cout << "Total solutions: " << solutions.size() << endl;
    for (const auto& sol : solutions)
    {
        for (const string& row : sol)
            cout << row << endl;
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    nQueens(n);
    return 0;
}
