// #include "Headerfile.h"

// // int fibonacci (int n)
// // {
// //     if (n == 0)
// //         return 1;
// //     return n * fibonacci(n - 1);

// // }
// // string palindrome (string n)
// // {
// //     string rev;

// //     rev += 
// // }
// #include <bits/stdc++.h> 
// #include <unordered_map>
// vector<int> anagramMapping(int n, vector<int> a, vector<int> b) {
//     vector<int> ans(n);
    
//     // edge case
//     if(a.empty() || b.empty())
//     return ans;
    
//     unordered_map<int,int> mp;
    
    
//     for(int i = 0; i < a.size(); i++)
//     {
//         mp[a[i]] = i;
//     }
//     for (const auto& pair : mp) {
//         std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
//     }

//     for(int i = 0; i < n; i++)
//     {
        
//          ans[i] = mp[b[i]];
//     }

//     return ans;
    
// }


// int main()
// {
//     // int arr[32];
//     // int X = 98;
        
//     // for(int i = 0; i < 32; i++)
//     // {
//     //     arr[i] = X & 1;
//     //     X << 1;
//     // }
    
//     // for(int i = 0; i < 32; i++)
//     // {
//     //     cout << arr[i];
//     // }
//     // string N = "naman";
//     // int num =n,soc;
//     // while(num != 0)
//     // {
//     //     soc += pow((num % 10), 3);
//     //     cout<< soc <<endl;
//     //     num = num / 10;
//     // }
//     // cout<< soc;
//     // if(n == soc)
//     //         cout<< 1;
        
//     //     else 
//     //         cout<< 0;
//     // edge case
//         // if(!N.size())
//         // return 0;
    
//         // long long ans;
        
//         // cout<< (N == palindrome(N));
        
//         // cout<< ans;

//         vector<int> a = {10,20,30,40,50};
//         vector<int> b = {20,10,40,50,30};
//         vector<int> ans = anagramMapping(a.size(),a,b);
//         for(int i = 0; i < a.size(); i++)
//         {
//             cout<< ans[i];
//         }
        
    
//     return 0;
// }
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int> v) {
    // edge case
    if (v.size() == 0)
        return 0;

    unordered_map<int, int> mp;

    for (int i = 0; i < v.size(); i++) {
        if (mp.find(v[i]) != mp.end()) {
            mp[v[i]] += 1;
        } else {
            mp[v[i]] = 1;
        }
    }

    int breakup = floor(v.size() / 2);

    for (auto x : mp) {
        if (x.second > breakup) {
            return x.first;
        }
    }

    return 0; // Default value indicating no majority element
}

int main() {
    // Example usage
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int majority = majorityElement(nums);
    cout << "Majority Element: " << majority << endl;
    return 0;
}
