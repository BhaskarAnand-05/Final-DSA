#include "Headerfile.h"

// RECURSIVE WAY// Time Complexity O(n^2)

// Dp wala tareeka best hai with TC O(n)

int counts_toreach_Nth_stair(int stairs)
{
    // base case
    if (stairs <= 1)
        return stairs;

    return counts_toreach_Nth_stair(stairs - 1) + counts_toreach_Nth_stair(stairs - 2);
}

int counts_toreach_Nth_stairs(int stairs, int start, int end)
{
    // base case
    if ((end - start) <= 1)
        return (end - start);

    return counts_toreach_Nth_stairs(stairs, start + 1, end) + counts_toreach_Nth_stairs(stairs, start + 2, end);
}

// DP WAY

int solve(int stairs, vector<int> dp)
{
    if (stairs <= 1)
        return 1;

    if (dp[stairs] != -1)
    {
        return dp[stairs];
    }

    dp[stairs] = (solve(stairs - 1, dp) + solve(stairs - 2, dp));

    return dp[stairs];
}

int count_distinct(int stairs)
{
    vector<int> dp(stairs + 1, -1);
    int ans = solve(stairs, dp);
    return ans;
}

int main()
{
    int stairs = 11;

    for (int i = 10; i > 0; i--)
    {
        cout << counts_toreach_Nth_stair(i + 1) << " ";
    }

    cout << endl;

    cout << counts_toreach_Nth_stairs(stairs, 0, stairs) << endl;
    cout << count_distinct(10);

    return 0;
}