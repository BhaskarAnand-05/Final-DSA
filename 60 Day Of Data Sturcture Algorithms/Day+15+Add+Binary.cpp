#include "Headerfile.h"

string add_padding(string binary, int len)
{
    string padding;
    for (int i = 0; i < len; i++)
    {
        padding.push_back('0');
    }

    binary = padding + binary;

    return binary;
}

pair<string, int> add_two(string binary1, string binary2)
{
    string ans;

    // base case
    if (binary1.empty() || binary2.empty())
        return make_pair(ans, 0);

    if (binary2.length() > binary1.length())
    {
        return add_two(binary2, binary1);
    }

    int len = binary1.length() - binary2.length();
    binary2 = add_padding(binary2, len);

    int carry = 0;

    int i = binary1.size() - 1;
    while (i >= 0)
    {
        if (binary1[i] == '1' && binary2[i] == '1')
        {
            if (carry == 1)
            {
                ans.push_back('1');
                carry = 0;
            }

            else
            {
                ans.push_back('0');
                carry = 1;
            }
        }
        else if (binary1[i] == '0' && binary2[i] == '0')
        {
            if (carry == 1)
            {
                ans.push_back('1');
                carry = 0;
            }

            else
            {
                ans.push_back('0');
                carry = 0;
            }
        }

        else
        {
            if (carry == 1)
            {
                ans.push_back('0');
                carry = 1;
            }

            else
            {
                ans.push_back('1');
                carry = 0;
            }
        }

        i--;
    }

    pair<string, int> p = make_pair(ans, carry);

    return p;
}

int main()
{
    string str1 = "101010101";
    string str2 = "10101";

    string res = add_two(str1, str2).first;
    reverse(res.begin(), res.end());
    cout << res << endl
         << add_two(str1, str2).second << endl;
    return 0;
}

// 1 0 1 0 1 0 1 0 1
// 0 0 0 0 1 0 1 0 1
// ------------------
// 1 0 1 1 0 1 0 1 0