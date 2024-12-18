#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<char, int> mp;

void enter_in_map(const string &original)
{
    for (char c : original)
    {
        mp[c]++;
    }
}

int slotScore(const string &original, const string &guess)
{
    int ans = 0;

    // Base case
    if (original.empty())
    {
        return -1;
    }

    if (guess.empty())
    {
        return 0;
    }

    mp.clear();
    enter_in_map(original);

    for (int i = 0; i < original.length() && i < guess.length(); i++)
    {
        if (mp.find(guess[i]) != mp.end())
        {
            ans += 1;
            mp.erase(guess[i]);
        }
        else if (original[i] == guess[i])
        {
            if (mp.find(guess[i]) != mp.end())
            {
                ans += 2;
                mp.erase(guess[i]);
            }
            else
            {
                ans += 1;
            }
        }
    }

    return ans;
}

int main()
{
    string original = "RGYB";
    string guess = "YGRR";
    int result = slotScore(original, guess);
    cout << "Slot score: " << result << endl;
    cout << (3 + 4) / 2;
    return 0;
}
