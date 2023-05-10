#include "Headerfile.h"
int findInteger(int n, int k)
{
    // edge case
    if (n == 0 || k == 0 || k > n)
        return 0;

    // int temp = 1;
    // int ans;

    // if(k <= (n+1)/2)
    // {
    //     while(temp <= k)
    //     {
    //         if(temp == k)
    //         ans = 2*temp - 1;

    //         temp++;
    //     }
    // }
    // if(k > (n+1)/2)
    // {
    //     int flag = k - ((n+1)/2);
    //     while(temp <= flag)
    //     {
    //         if(temp == flag)
    //         ans = 2*temp;

    //         temp++;
    //     }
    // }

    // return ans;
    vector<int> array;

    for (int num = 1; num <= n; num++)
    {
        if (num % 2 != 0)
            array.push_back(num);
    }

    for (int num = 1; num <= n; num++)
    {
        if (num % 2 == 0)
            array.push_back(num);
    }
    for (int i = 0; i < array.size(); i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    return array[k];
}

int main()
{
    int num = 9;
    int k = 4;
    
    

    cout<<findInteger(num,k);

    return 0;
}