#include "Headerfile.h"

// ### Set 0 to the matrix
// APPROACH 1 Using Row and Column Vector TC(n^2) SC(n+m)
// void setRow(vector<vector<int>> &matrix, vector<int> row, int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (row[i] == 1)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 matrix[i][j] = 1;
//             }
//         }
//     }

//     return;
// }

// void setColumn(vector<vector<int>> &matrix, vector<int> column, int m, int n)
// {
//     for (int i = 0; i < m; i++)
//     {
//         if (column[i] == 1)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 matrix[j][i] = 1;
//             }
//         }
//     }

//     return;
// }

// void SetMatrix(vector<vector<int>> &matrix, int n, int m)
// {
//     // base case
//     if (matrix.empty())
//     {
//         return;
//     }

//     vector<int> row(n, 0);
//     vector<int> column(m, 0);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 1)
//             {
//                 row[i] = 1;
//                 column[j] = 1;
//             }
//         }
//     }

//     setRow(matrix, row, n, m);
//     setColumn(matrix, column, m, n);

//     return;
// }

// APPROACH 2 Using no vector like Row and Column

void setRow(vector<vector<int>> &matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 1)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = 1;
            }
        }
    }

    return;
}

void setColumn(vector<vector<int>> &matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (matrix[0][i] == 1)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[j][i] = 1;
            }
        }
    }

    return;
}

void SetMatrix(vector<vector<int>> &matrix, int n, int m)
{
    // base case
    if (matrix.empty())
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][0] = 1;
                matrix[0][j] = 1;
            }
        }
    }

    printmatrix(matrix, 3, 3);
    cout << endl;

    setColumn(matrix, m, n);
    setRow(matrix, n, m);

    return;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 0},
                                  {0, 0, 1},
                                  {0, 0, 0}};

    SetMatrix(matrix, 3, 3); // Callling set matrix function

    printmatrix(matrix, 3, 3);
    return 0;
}