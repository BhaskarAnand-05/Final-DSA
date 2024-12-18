#include "Headerfile.h"

string digit2string(int digit)
{
    switch (digit)
    {
    case 1:
        return "One";
        break;
    case 2:
        return "Two";
        break;
    case 3:
        return "Three";
        break;
    case 4:
        return "Four";
        break;
    case 5:
        return "Five";
        break;
    case 6:
        return "Six";
        break;
    case 7:
        return "Seven";
        break;
    case 8:
        return "Eight";
        break;
    case 9:
        return "Nine";
        break;

    default:
        break;
    }
}

void say_digits(int val)
{
    // base case
    if (val == 0)
        return;

    string ans;

    // while (val > 0)
    // {
    //     int digit = val % 10;

    //     ans = digit2string(digit) + ' ' + ans;

    //     val /= 10;
    // }

    int digit = val % 10;

    ans = digit2string(digit) + ' ' + ans;

    val /= 10;

    say_digits(val);

    cout << ans;

    return;
}

int main()
{
    int val = 5234;

    say_digits(val);

    return 0;
}