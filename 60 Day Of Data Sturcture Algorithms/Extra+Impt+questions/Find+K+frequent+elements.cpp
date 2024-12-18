#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

unordered_map<int, int> mp;
priority_queue<pair<int, int>> pq;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;

    // base case
    if (nums.size() == 0)
        return ans;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    while (!mp.empty())
    {
        pq.push(make_pair(mp.begin()->first, mp.begin()->second));
        mp.erase(mp.begin());
    }

    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> ans = topKFrequent(nums, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}