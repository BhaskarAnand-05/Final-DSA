#include "Headerfile.h"
#include <bits/stdc++.h>

// O(N^2) SOLUTION BUT RECURSIVE

void solve(vector<vector<long long int>> &arr, vector<long long int> &temp, int i, int j)
{
    if (j > i)
        return;

    if (j == 0 || j == i)
    {
        temp.push_back(1);
    }

    else
    {
        temp.push_back(arr[i - 1][j - 1] + arr[i - 1][j]);
    }

    solve(arr, temp, i, j + 1);
    return;
}

vector<vector<long long int>> PrintPascal(int n)
{
    vector<vector<long long int>> arr; // Initialize the vector with zeros

    // base case
    if (n <= 0)
        return arr;

    for (int i = 0; i < n; i++)
    {
        vector<long long int> temp;
        solve(arr, temp, i, 0);
        arr.push_back(temp);
    }

    return arr;
}

// O(N^2) SOLUTION BUT ITERATIVE

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> arr; // Initialize the vector with zeros

    if (n <= 0)
        return arr;

    for (int i = 0; i < n; i++)
    {
        vector<long long int> temp;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                temp.push_back(1);
            }

            else
            {
                temp.push_back(arr[i - 1][j - 1] + arr[i - 1][j]);
            }
        }
        arr.push_back(temp);
    }

    return arr;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<long long int>> ans = printPascal(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " " << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    vector<vector<long long int>> res = PrintPascal(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " " << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}