#include <iostream>
#include <vector>

using namespace std;

//  this code will return true if the queen is safe or not
bool isSafe(int row, int col, vector<int> &placement)
{
    //  check the current position with the previous queen positions
    for (int i = 0; i < row; i++)
    {
        /*
        placement[i] == col -- > this is for checking if the queen is in the same  caloumn or not
        placement[i] - i = col - row --> this for checking if the queen falls in the right diagonal
        placement[i] + i == col - row --> this is for checking if the queen falls in the left diagonal

        if any of the abovbe statement are true then the position of the queen is not safes
        */
        if (placement[i] == col || placement[i] - i == col - row || placement[i] + i == col + row)
        {
            return false;
        }
    }

    return true;
}

//  this code is for checking the each row and column
void solveNQueens(int n, int row, vector<int> &placement, vector<vector<int>> &solutions)
{
    //  if we have reached the end of the row then we have found a solution
    if (row == n)
    {
        solutions.push_back(placement);
        return;
    }

    //  or else try every cell of the column in each row
    for (int col = 0; col < n; ++col)
    {
        //  if the position is safe then place the queen
        if (isSafe(row, col, placement))
        {
            placement[row] = col;
            solveNQueens(n, row + 1, placement, solutions);
        }
    }
}

//  function for solving the N queens
vector<vector<int>> solveNQueens(int n)
{
    //  this vector of vector is used to store the result
    vector<vector<int>> solutions;
    vector<int> placement(n);
    solveNQueens(n, 0, placement, solutions);
    return solutions;
}

int main()
{
    int n;
    cout << "Enter the number of Queens" << endl;
    cin >> n;
    vector<vector<int>> ans = solveNQueens(n);
    cout << "Total solutions: " << ans.size() << endl;
    cout << "Printing solutions:\n";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < n; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
