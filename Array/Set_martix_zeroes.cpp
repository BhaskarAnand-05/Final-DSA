#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // This is for rows
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    for (int k = 0; k < m; k++)
                    {
                        if (k != j)
                        {
                            matrix[i][k] = -1;
                        }
                    }
                }
            }
        }

        //  Same Goes for Columns
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (matrix[j][i] == 0)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (k != i)
                        {
                            matrix[k][j] = -1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    Solution().setZeroes(matrix);

    for (const auto &row : matrix)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
