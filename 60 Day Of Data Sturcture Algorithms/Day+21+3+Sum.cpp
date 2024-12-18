#include "Headerfile.h"

// BRUTE FORCE SOLUTION
// vector<vector<int>> three_sum(vector<int> arr)
// {

//     set<vector<int>> st;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = i + 1; j < arr.size(); j++)
//         {
//             int sum = arr[j] + arr[i];
//             for (int k = j + 1; k < arr.size(); k++)
//             {
//                 if (sum + arr[k] == 0)
//                 {
//                     vector<int> temp = {arr[i], arr[j], arr[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }

//     vector<vector<int>> result(st.begin(), st.end());
//     return result;
// }

// BETTER SOLUTION IS TO DONT UDKE THE THIRD LOOP INSTEAD USE THE SET O(N^2)
// vector<vector<int>> three_sum(vector<int> arr)
// {

//     set<vector<int>> st;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         set<int> k;
//         for (int j = i + 1; j < arr.size(); j++)
//         {
//             int sum = arr[j] + arr[i];
//             if (k.find(-(sum)) != k.end())
//             {
//                 vector<int> temp = {arr[i], arr[j], -(sum)};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             k.insert(arr[j]);
//         }
//     }

//     vector<vector<int>> result(st.begin(), st.end());
//     return result;
// }

//  OPTIMIZED SOLUTION O(N*log(N)+ N^2)

vector<vector<int>> three_sum(vector<int> arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();

    // ignoring duplicates

    for (int i = 0; i < arr.size(); i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0)
                j++;

            else if (sum > 0)
                k--;

            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> ans;
    vector<int> array = {-1, 0, 1, 2, -1, -4};

    ans = three_sum(array);

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