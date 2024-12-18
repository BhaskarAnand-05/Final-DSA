#include <iostream>
#include <vector>
using namespace std;

// QUE 1 MERGE SORT USING RECURSION

void merge(vector<int> &array, int start, int mid, int end)
{
    int leftsize = mid - start + 1;
    int rightsize = end - mid;

    vector<int> left(leftsize);
    vector<int> right(rightsize);

    for (int i = 0; i < leftsize; i++)
    {
        left[i] = array[i + start];
    }
    for (int i = 0; i < rightsize; i++)
    {
        right[i] = array[i + mid + 1];
    }

    int left_index = 0, right_index = 0, index = start;
    while (left_index < leftsize && right_index < rightsize)
    {
        if (left[left_index] < right[right_index])
        {
            array[index] = left[left_index];
            left_index++;
        }
        else
        {
            array[index] = right[right_index];
            right_index++;
        }
        index++;
    }

    while (left_index < leftsize)
    {
        array[index] = left[left_index];
        left_index++;
        index++;
    }

    while (right_index < rightsize)
    {
        array[index] = right[right_index];
        right_index++;
        index++;
    }
}

void merge_sort(vector<int> &array, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(array, start, mid);

    merge_sort(array, mid + 1, end);

    merge(array, start, mid, end);

    return;
}

// QUE 2 INVERSION COUNT PROBLEM

int solve(vector<int> &array, int start, int mid, int end)
{
    int inversion_count_val = 0;

    int leftsize = mid - start + 1;
    int rightsize = end - mid;

    vector<int> left(leftsize);
    vector<int> right(rightsize);

    for (int i = 0; i < leftsize; i++)
    {
        left[i] = array[i + start];
    }
    for (int i = 0; i < rightsize; i++)
    {
        right[i] = array[i + mid + 1];
    }

    int left_index = 0, right_index = 0, index = start;
    while (left_index < leftsize && right_index < rightsize)
    {
        if (left[left_index] > right[right_index]) // Use <= instead of <
        {
            inversion_count_val += (leftsize - left_index);
            array[index++] = right[right_index++];
        }
        else
        {
            array[index++] = left[left_index++];
        }
    }

    while (left_index < leftsize)
    {
        array[index++] = left[left_index++];
    }

    while (right_index < rightsize)
    {
        array[index++] = right[right_index++];
    }

    return inversion_count_val;
}

int inversion_count(vector<int> &array, int start, int end)
{

    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;

    int inversion_count_val = inversion_count(array, start, mid);
    inversion_count_val += inversion_count(array, mid + 1, end);
    inversion_count_val += solve(array, start, mid, end);

    return inversion_count_val;
}

int main()
{
    vector<int> arr = {12, 15, 121, 564, 1, 6, 89, 784, 56};
    vector<int> array = {12, 15, 121, 564, 1, 6, 89, 784, 56};

    merge_sort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << inversion_count(array, 0, array.size() - 1) << endl;

    return 0;
}
