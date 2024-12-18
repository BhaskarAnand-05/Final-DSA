#include "Headerfile.h"

int fibonacci(int n)
{
    // base case
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    return fibonacci(n - 2) + fibonacci(n - 1);
}

// using for loop \\ ITERATIVE WAY

void fib(int n)
{
    int first = 0, second = 1;

    cout << first << " " << second << " ";
    for (int i = 3; i < n; i++)
    {
        int third = first + second;
        cout << third << " ";
        first = second;
        second = third;
    }
    cout << endl;
}

int main()
{
    int n = 1;
    while (n < 20)
    {
        cout << fibonacci(n) << " ";
        n++;
    }
    cout << endl;

    fib(20);
    return 0;
}