#include "Headerfile.h"

//  print array
void print(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

// QUE 1 BUUBLE SORT
//  ITERATIVE
vector<int> bubble_sort(vector<int> arr)
{
    // base case
    if (arr.empty())
        return arr;

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                print(arr);
            }
        }
    }
    return arr;
}
// RECURSIVE
void rec_bubble_sort(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
        return;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    rec_bubble_sort(arr, n - 1);
}

// QUE2 SELECTION SORT
//  ITERATIVE
vector<int> selection_sort(vector<int> arr)
{
    // base case
    if (arr.empty())
        return arr;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
                print(arr);
            }
        }
    }
    return arr;
}

// RECURSIVE
void rec_selection_sort(vector<int> &arr, int i)
{
    if (i > arr.size())
        return;

    for (int j = i + 1; j < arr.size(); j++)
    {
        if (arr[i] > arr[j])
        {
            swap(arr[i], arr[j]);
        }
    }

    rec_selection_sort(arr, ++i);
}

// QUE2 INSERTION SORT
//  ITERATIVE
vector<int> insertion_sort(vector<int> arr)
{
    // base case
    if (arr.empty())
        return arr;

    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (temp < arr[j])
            {
                arr[j + 1] = arr[j];
                print(arr);
            }
            else
            { // ruk jao
                break;
            }
        }
        arr[j + 1] = temp;
    }
    return arr;
}

// RECURSIVE
void rec_insertion_sort(vector<int> &arr, int i)
{
    if (i >= arr.size())
        return;

    int temp = arr[i];
    int j = i - 1;
    for (; j >= 0; j--)
    {
        if (temp < arr[j])
        {
            arr[j + 1] = arr[j];
        }
        else
        { // ruk jao
            break;
        }
    }
    arr[j + 1] = temp;

    rec_insertion_sort(arr, ++i);
}

int main()
{
    vector<int> array = {12, 15, 121, 564, 1, 6, 89, 784, 56};

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;

    vector<int> ans = bubble_sort(array);

    rec_bubble_sort(array, array.size() - 1);

    cout << endl;
    cout << endl;
    cout << endl;
    print(ans);
    cout << endl;
    cout << endl;
    cout << endl;
    print(array);

    //  SELECTION SORT
    vector<int> a = {16, 26, 154, 987, 1, 5, 78, 235, 89};

    print(a);
    cout << endl;
    cout << endl;
    cout << endl;

    vector<int> res = selection_sort(a);

    rec_selection_sort(a, 0);

    cout << endl;
    cout << endl;
    cout << endl;
    print(res);
    cout << endl;
    cout << endl;
    cout << endl;
    print(a);

    //  INSERTION SORT
    vector<int> arr = {98, 75, 897, 42, 3, 56, 12, 39, 16};

    print(arr);
    cout << endl;
    cout << endl;
    cout << endl;

    vector<int> result = insertion_sort(arr);

    rec_insertion_sort(arr, 0);

    cout << endl;
    cout << endl;
    cout << endl;
    print(result);
    cout << endl;
    cout << endl;
    cout << endl;
    print(arr);

    return 0;
}