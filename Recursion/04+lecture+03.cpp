#include "Headerfile.h"

// QUE 1 FUNTION TO CHECK THAT THE ARRAY IS SORTED OR NOT

bool solve(vector<int> a, int i, int j)
{
    if (j == a.size() - 1 && a[i] < a[j])

        return true;

    int first = a[i];
    int second = a[j];

    if (first > second)
        return false;

    return solve(a, ++i, ++j);
}

bool IsSorted(vector<int> arr)
{
    // base case
    if (arr.empty())
        return true;

    return solve(arr, 0, 1);
}

//  QUE 2  FUNCTION TO CALCULATE THE SUM OF ARRAY

void find_sum(vector<int> arr, int &sum, int index)
{
    // base case
    if (index > arr.size() - 1)
        return;

    sum += arr[index];
    // cout << sum << endl;

    find_sum(arr, sum, ++index);
    return;
}

// QUE 3  LINEAR SEARCH USING RECURSION

int linear_search(vector<int> arr, int element, int index)
{
    // base case
    if (arr.size() == 0)
        return -1;
    if (arr.size() == 1 && element == arr[0])
        return 0;
    if (index > arr.size() - 1)
        return -1;

    if (arr[index] == element)
    {
        return index;
    }

    return linear_search(arr, element, ++index);
}
int count = 0;
int Linear_search(int *arr, int element, int size)
{
    // base case
    if (size == 0)
        return -1;
    if (size == 1 && element == arr[0])
        return 0;
    if (::count > size - 1)
    {
        return -1;
    }

    if (arr[0] == element)
    {
        return ::count;
    }

    ::count += 1;
    return Linear_search(arr + 1, element, size);
}
int solve(vector<int> array, int beg, int end, int element)
{
    if (beg > end)
        return -1;

    int mid = (beg + end) / 2;

    if (array[mid] > element)
    {
        return solve(array, beg, mid, element);
    }
    else if (array[mid] < element)
    {
        return solve(array, mid + 1, end, element);
    }
    else if (array[mid] == element)
        return mid;
}

int binary_search(vector<int> arr, int element)
{
    // base case
    if (arr.size() == 0)
        return -1;

    return solve(arr, 0, arr.size() - 1, element);
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 15, 16, 17, 18};
    int array[] = {2, 4, 6, 8, 10, 12, 14, 15, 16, 17, 18};
    cout << IsSorted(arr) << endl;

    int sum = 0;
    find_sum(arr, sum, 0);

    cout << sum << endl;

    int element = 55;
    cout << linear_search(arr, element, 0) << endl;
    cout << Linear_search(array, element, 11) << endl;

    cout << binary_search(arr, element) << endl;

    return 0;
}