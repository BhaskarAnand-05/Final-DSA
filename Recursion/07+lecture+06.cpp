#include "Headerfile.h"

// QUE -1 QUICK SORT  USING RECURSION

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];

    // count elements less than pivot
    int count = 0;

    for (int i = start + 1; i < arr.size(); i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int num = count;
    // cout << num << endl;

    int pivot_index = start + num;

    swap(arr[start], arr[pivot_index]);

    int i = start;
    int j = end;

    while (i < pivot_index && j > pivot_index)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivot_index && j > pivot_index)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    printvector(arr);

    return pivot_index;
}

void quick_sort(vector<int> &arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);

    return;
}

int main()
{
    vector<int> arr = {12, 156, 1, 89, 41, 69, 121, 35};
    printvector(arr);

    quick_sort(arr, 0, arr.size() - 1);

    printvector(arr);
    return 0;
}