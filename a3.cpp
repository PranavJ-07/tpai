#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(int col, int n, vector<string> &board, vector<bool> &rows, vector<bool> &main_diag, vector<bool> &anti_diag)
{
    if (col == n)
    {
        for (auto r : board)
        {
            cout << r << endl;
        }
        cout << " ----------------------\n";
        return;
    }

    for (int row = 0; row < n; row++)
    {
        int m_idx = row - col + n - 1;
        int a_idx = row + col;

        if (!rows[row] && !main_diag[m_idx] && !anti_diag[a_idx])
        {
            board[row][col] = 'Q';
            rows[row] = main_diag[m_idx] = anti_diag[a_idx] = true;

            backtrack(col + 1, n, board, rows, main_diag, anti_diag);

            board[row][col] = '.';
            rows[row] = main_diag[m_idx] = anti_diag[a_idx] = false;
        }
    }
}

void solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<bool> rows(n, false);
    vector<bool> main_diag(2 * n - 1, false);
    vector<bool> anti_diag(2 * n - 1, false);

    backtrack(0, n, board, rows, main_diag, anti_diag);
}

int main()
{
    int n;
    cout << "Enter value of N : ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive integer\n";
        return 0;
    }

    solveNQueens(n);

    return 0;
}