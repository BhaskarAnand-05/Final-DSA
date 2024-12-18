#include "Headerfile.h"
using namespace std;

bool find_anagram(string S1, string S2)
{
    // edge case
    if (S1.empty() || S2.empty())
    {
        return false;
    }

    sort(S1.begin(), S1.end());
    cout << S1 << endl;
    sort(S2.begin(), S2.end());
    cout << S2 << endl;

    for (int i = 0; i < S1.size(); i++)
    {
        if (S1[i] != S2[i])
            return false;
    }
    return true;
}

int main()
{
    string S = "bhaskar";
    string S2 = "askbhar";
    string S3 = "abhapkr";

    cout << bool(find_anagram(S, S2)) << endl;
    cout << bool(find_anagram(S, S3)) << endl;
    return 0;
}