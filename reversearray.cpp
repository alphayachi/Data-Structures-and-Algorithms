#include <iostream>
using namespace std;

void revarr(int *arr, int start, int end)
{

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    int end = n - 1;
    revarr(arr, 0, end);
    for (int i = 0; i <= end; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}