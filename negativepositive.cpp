#include <iostream>
using namespace std;

void arrange(int *a, int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] < 0)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
}

int main()
{
    int a[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(a) / sizeof(a[0]);
    arrange(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}