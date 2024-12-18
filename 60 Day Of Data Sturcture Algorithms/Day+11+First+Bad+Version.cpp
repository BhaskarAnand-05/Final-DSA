#include "Headerfile.h"
#include <map>

unordered_map<int, bool> mp;

void setbad_good(vector<int> versions, int bad)
{
    for (int i = 0; i < versions.size(); i++)
    {
        if (versions[i] >= bad)
        {
            mp[versions[i]] = true;
        }

        else
            mp[versions[i]] = false;
    }

    return;
}

bool isbadversion(int version)
{
    // edge case
    if (version < 0)
        return false;

    if (mp.find(version) != mp.end())
    {
        return mp[version];
    }
}
int main()
{
    vector<int> versions = {1, 2, 3, 4, 5, 6, 7};

    int bad = 4;

    setbad_good(versions, bad);

    cout << isbadversion(2) << endl;
    cout << isbadversion(4) << endl;
    cout << isbadversion(7) << endl;
    return 0;
}