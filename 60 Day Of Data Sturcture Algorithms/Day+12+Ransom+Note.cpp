#include "Headerfile.h"
#include <map>

unordered_map<char, int> mp;

bool Ransom_Note(string magazine, string ransomNote)
{
    int flag = 0;

    // base case
    if (magazine.size() == 0 && ransomNote.size() == 0)
        return true; // dono  null ho to true

    if (ransomNote.size() == 0)
        return true; // sirf ransomNote null ho to true

    if (magazine.size() == 0)
        return false; // magazine null ho to false

    for (int i = 0; i < magazine.size(); i++) // mp me magazine ka har ek char daal do
    {
        mp[magazine[i]]++;
    }

    for (int i = 0; i < ransomNote.size(); i++)
    {
        if (mp[ransomNote[i]] < 1)
        {
            return false;
        }

        mp[ransomNote[i]]--;
    }

    return true;
}

// bool Ransom_Note(string magazine, string ransomNote)
// {
//     if (magazine.empty() && ransomNote.empty())
//         return true;

//     if (ransomNote.empty())
//         return true;

//     if (magazine.empty())
//         return false;

//     std::map<char, int> mp;
//     for (int i = 0; i < magazine.size(); i++)
//     {
//         mp[magazine[i]]++; // Increment the count of each character in the magazine
//     }

//     for (int i = 0; i < ransomNote.size(); i++)
//     {
//         if (mp[ransomNote[i]] == 0) // Character not found in the magazine
//         {
//             return false;
//         }
//         mp[ransomNote[i]]--; // Decrementing is not required for checking existence
//     }

//     return true;
// }

int main()
{
    string ransomNote = "aka";
    string magazine = "Bhaskar";

    cout << Ransom_Note(magazine, ransomNote);

    return 0;
}