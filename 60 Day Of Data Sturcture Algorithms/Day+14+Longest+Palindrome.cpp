#include "Headerfile.h"
#include <map>
#define DIV(x) int(x / 2)

unordered_map<char, int> mp;

void enter_in_map(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        mp[str[i]]++;
    }
}

int longest_palindrome(string str)
{
    int len = 0;
    // base case
    if (str.empty())
        return -1;

    enter_in_map(str);

    for (auto x : mp)
    {
        if (x.second > 1)
        {
            len += 2 * DIV(x.second);
        }
    }

    return len + 1;
}

int main()
{
    string str = "bananas";

    cout << longest_palindrome(str);

    return 0;
}