#include <iostream>
#include <vector>
using namespace std;

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
    for (int i = mid + 1; i < end; i++)
    {
        right[i - mid - 1] = array[i];
    }

    int left_index = 0, right_index = 0, index = start;
    while (left_index < leftsize && right_index < rightsize)
    {
        if (left[left_index] < right[right_index])
        {
            array[index] = left[left_index];
            left_index++;
            index++;
        }
        else
        {
            array[index] = left[right_index];
            right_index++;
            index++;
        }
    }

    while (left_index < leftsize)
    {
        array[index] = left[left_index];
        left_index++;
        index++;
    }

    while (right_index < rightsize)
    {
        array[index] = left[right_index];
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

int main()
{
    vector<int> arr = {12, 15, 121, 564, 1, 6, 89, 784, 56};

    merge_sort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
