#include "Headerfile.h"

// QUE 1 SUBSETS (POWER SET)

void solve(vector<int> set, vector<vector<int>> &ans, int index, vector<int> temp)
{
    if (index >= set.size())
    {
        ans.push_back(temp);
        return;
    }

    // exclude
    solve(set, ans, index + 1, temp);

    // include
    // cout << set[index] << endl;
    temp.push_back(set[index]);
    solve(set, ans, index + 1, temp);
}

vector<vector<int>> power_set(vector<int> set)
{
    vector<vector<int>> ans; // ans
    // base case
    if (set.empty())
    {
        return ans;
    }

    vector<int> temp;
    solve(set, ans, 0, temp);

    return ans;
}

int main()
{
    vector<int> set = {1, 2, 3};

    vector<vector<int>> ans = power_set(set);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}