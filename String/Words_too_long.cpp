#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <process.h>
#include <iomanip>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <fstream>

using namespace std;
int count_letter(string word)
{
    return word.length();
}

string word_too_long(string word)
{
    int count = count_letter(word);

    // BASE CASE: word is equal or smaller to 10 carracters
    if (count <= 10)
    {
        return word;
    }

    int no_in_between = count - 2;

    string result = word[0] + to_string(no_in_between) + word[count - 1];

    return result;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string word_1;
        cin >> word_1;

        string abbrev_1 = word_too_long(word_1);

        cout << abbrev_1 << endl;
    }

    return 0;
}