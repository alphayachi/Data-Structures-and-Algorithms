#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int mx = max(arr[mid], arr[high]);
    mx++;
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        int e1 = arr[i] % mx;
        int e2 = arr[j] % mx;
        if (e1 <= e2)
        {
            arr[k] += e1 * mx;
            k++;
            i++;
        }
        else
        {
            arr[k] += e2 * mx;
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        int e1 = arr[i] % mx;
        arr[k] += e1 * mx;
        i++;
        k++;
    }
    while (j <= high)
    {
        int e2 = arr[j] % mx;
        arr[k] += e2 * mx;
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = arr[i] / mx;
    }
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int nums[] = {12, 11, 13, 5, 6, 7};
    int nums_size = sizeof(nums) / sizeof(nums[0]);

    mergesort(nums, 0, nums_size - 1);

    for (int i = 0; i < nums_size; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}