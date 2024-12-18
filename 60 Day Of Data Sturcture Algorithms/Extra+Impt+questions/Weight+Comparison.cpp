// MY APPROACH OF RECURSION WHICH GAVE WRONG OUTPUT

// CORRECT APPROACH WAS USING DP That in will practice at last of this month

#include "Headerfile.h"

int count = 0; //  to check about the no of valid matrices

void solve(vector<vector<int>> mat, int row, int col, int N, int weight)
{
    // base case
    if (row + N > mat.size() || col + N > mat[0].size())
        return;

    int sum_of_weights = 0;

    for (int i = row; i < row + N; i++)
    {
        for (int j = col; j < col + N; j++)
        {
            sum_of_weights += mat[i][j];
        }
    }

    // cout << sum_of_weights << endl;

    if (sum_of_weights <= weight)
    {
        ::count++;
    }

    solve(mat, row + 1, col, N, weight);
    solve(mat, row, col + 1, N, weight);
    // solve(mat, row + 1, col + 1, N, weight);
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    cout << mat.size() << " " << mat[0].size() << endl;

    int N = 2;
    int weight = 60;

    solve(mat, 0, 0, N, weight);

    cout << ::count << endl;

    return 0;
}