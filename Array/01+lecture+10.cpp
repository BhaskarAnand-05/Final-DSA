#include "Headerfile.h"
// SWAP ALTERNATE
void swap_alternate(int arr[], int n)
{
    for (int i = 0; i < n; i += 3)
    {
        if (i + 1 < n)
            swap(arr[i], arr[i + 2]);
    }

    return;
}

// FIND UNIQUE
int findUnique(int *arr, int size)
{
    std::unordered_map<int, int> mp;

    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }
    for (auto x : mp)
    {
        if (x.second == 1)
        {
            return x.first;
        }
    }
}

// ########New Appraoch := XOR
int find_unique(int *arr, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}

// TWO SUM
int ZeroPairSum(int n, vector<int> arr)
{
    map<int, int> mp;

    // bas e case
    if (arr.empty() || n == 1)
    {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        int target = -arr[i];

        if (mp.find(target) != mp.end())
        {
            count++;
        }
    }
    return count / 2;
}

// TRIPLET SUM
vector<vector<int>> tripletsum(vector<int> arr, int target)
{
    vector<vector<int>> result;

    // base case
    if (arr.empty())
        return result;

    unordered_map<int, int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        temp[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int sum = arr[i] + arr[j];

            if (temp.find(target - sum) != temp.end() && (target - sum) != arr[i] && (target - sum) != arr[j])
            {
                vector<int> res = {arr[i], arr[j], target - sum};
                result.push_back(res);

                if (temp[target - sum] == 0)
                {
                    temp.erase(target - sum);
                }
                else
                    temp[target - sum]--;
            }
        }
    }

    return result;
}

vector<vector<int>> triplet_sum(vector<int> arr, int target)
{
    vector<vector<int>> result;

    // Sort the input array to make it easier to find triplets.
    sort(arr.begin(), arr.end());

    int n = arr.size();

    for (int i = 0; i < n - 2; i++)
    {
        // Skip duplicate elements.
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == target)
            {
                result.push_back({arr[i], arr[left], arr[right]});

                // Skip duplicate elements.
                while (left < right && arr[left] == arr[left + 1])
                    left++;
                while (left < right && arr[right] == arr[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    // swap_alternate(arr, 10);
    // int ans = find_unique(arr, 11);
    // int ans = ZeroPairSum(11, arr);

    auto ans = triplet_sum(arr, 12);

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