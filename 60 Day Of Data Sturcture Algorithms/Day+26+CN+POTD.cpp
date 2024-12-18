#include "Headerfile.h"
char solve(int rem)
{

    char array[58] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    return array[0 + rem];
}
string encodeBase58(int N)
{
    string ans;
    // base case
    if (N == 0)
    {
        return "1";
    }

    if (N < 58)
    {
        ans.push_back(solve(N));
        return ans;
    }

    int rem = N % 58;
    cout << rem << endl;
    int div = N / 58;
    cout << div << endl;

    ans.push_back(solve(div));
    ans.push_back(solve(rem));

    return ans;
}

int main()
{
    int n = 67;

    cout << encodeBase58(n) << endl;
    return 0;
}
