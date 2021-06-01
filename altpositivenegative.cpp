#include <bits/stdc++.h>
using namespace std;

void rearrange(int *arr, int i, int j)
{
    while (j > i)
    {
        arr[j] = arr[j - 1];
        j--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sign;
    if (arr[0] < 0)
    {
        sign = 1;
    }
    else
    {
        sign = -1;
    }
    for (int i = 1; i < n; i++)
    {
        int j;
        for (j = i; j < n; j++)
        {
            if (sign == 1 && arr[j] >= 0)
            {
                break;
            }
            else if (sign == 1 && arr[j] < 0)
            {
                continue;
            }
            else if (sign == -1 && arr[j] < 0)
            {
                break;
            }
            else if (sign == -1 && arr[j] >= 0)
            {
                continue;
            }
        }
        if (j == n)
        {
            break;
        }
        int temp = arr[j];
        rearrange(arr, i, j);
        arr[i] = temp;
        sign *= -1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}