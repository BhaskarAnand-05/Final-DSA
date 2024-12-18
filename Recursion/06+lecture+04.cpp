#include "Headerfile.h"
#define mod(x) x % 2

// QUE1 REVERSE STRING

void solve(string &str, int i, int j)
{
    if (i <= j)
        return;

    int temp = str[j];
    str[j] = str[i];
    str[i] = temp;

    solve(str, --i, ++j);
    return;
}
void Solve(string &str, int i)
{
    int len = str.length() - 1;
    if (i <= len / 2)
        return;

    int temp = str[len - i];
    str[len - i] = str[i];
    str[i] = temp;

    Solve(str, --i);
    return;
}

string reverse_str(string &str)
{
    // base case
    if (str.length() == 0)
        return str;

    // solve(str, str.length() - 1, 0);
    Solve(str, str.length() - 1);

    return str;
}

// QUE 2 CHECK PLAINDROME

bool check(string str, int i, int j)
{
    if (i <= j)
        return true;

    if (str[i] != str[j])
        return false;

    return check(str, --i, ++j);
}

bool check_palindrome(string str)
{
    //  base case
    if (str.length() == 0)
        return true;

    // Solve(str, str.length() - 1);

    return check(str, str.length() - 1, 0);
}

// QUE 3 CALCULATE THE POWER OF BASE
long double power(int a, int b)
{
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    int ans = power(a, b / 2);

    if (mod(b) == 0)
    {
        ans = ans * ans;
    }
    else
    {
        ans = a * ans * ans;
    }

    return ans;
}

int main()
{
    string s = "Jassaj";

    cout << s << endl;
    cout << reverse_str(s) << endl;

    cout << check_palindrome(s) << endl;

    cout << power(2, 30) << endl;
    return 0;
}