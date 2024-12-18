#include "Headerfile.h"

// aim is to solve in O(logn)
int binary_search_fast(vector<int> nums, int target, int start, int end)
{
    
    int mid = (start+end)/2;

    if(target < nums[mid])
    {
        return binary_search_fast(nums, target, start, mid);
    }
    else if(target == nums[mid])
    {
        return mid;
    }
    else
    {
        return binary_search_fast(nums, target, mid+1, end);

    }
}

int Binary_search(vector<int> nums, int target)
{
    // base case
    if(nums.size() == 0 || target == -1) return -1;
    
    int start = 0;
    int end = nums.size();
    // mid = (start + end)/2;
    
    return binary_search_fast(nums, target,start,end);
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9};

    cout<< Binary_search(nums, 9);
    return 0;
}