#include <iostream>
#include <climits>
using namespace std;

pair<int, int> minmax(int *arr, int start, int end)
{
    pair<int, int> m;
    if (start == end)
    {
        m.first = arr[start];
        m.second = arr[start];
        return m;
    }
    else if ((end - start) == 1)
    {
        if (arr[start] > arr[end])
        {
            m.first = arr[end];
            m.second = arr[start];
        }
        else
        {
            m.first = arr[start];
            m.second = arr[end];
        }
        return m;
    }
    else
    {
        int mid = (end + start) / 2;
        pair<int, int> left = minmax(arr, start, mid);
        pair<int, int> right = minmax(arr, mid + 1, end);
        if (left.first < right.first)
        {
            m.first = left.first;
        }
        else
        {
            m.first = right.first;
        }
        if (left.second > right.second)
        {
            m.second = left.second;
        }
        else
        {
            m.second = right.second;
        }
        return m;
    }
}

int main()
{
    int arr[] = {5, 19, 20, 47, 16, -5, -9, 0};

    int n = sizeof(arr) / sizeof(int);
    int end = n - 1;
    pair<int, int> ans = minmax(arr, 0, end);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}