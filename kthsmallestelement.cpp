#include <iostream>
using namespace std;

void merge(int *arr, int low, int high)
{
    int mid = (low + high) / 2;
    int n1 = mid + 1;
    int n2 = high - mid;
    int k = low;
    int leftarr[100000], rightarr[100000];
    for (int i = 0; i < n1; i++)
    {
        leftarr[i] = arr[low];
        low++;
    }
    for (int i = 0; i < n2; i++)
    {
        rightarr[i] = arr[mid + 1];
        mid++;
    }
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (leftarr[i] < rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergesort(int *arr, int low, int high)
{
    if (high == low)
    {
        return;
    }
    int mid = (high + low) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, high);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[100000];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        mergesort(arr, 0, n - 1);
        cout << arr[k - 1];
    }
    return 0;
}