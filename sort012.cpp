#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[100000];
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            zero++;
        }
        else if (arr[i] == 1)
        {
            one++;
        }
        else if (arr[i] == 2)
        {
            two++;
        }
    }
    int i = 0;
    while (zero--)
    {
        arr[i] = 0;
        i++;
        cout << "0 ";
    }
    while (one--)
    {
        arr[i] = 1;
        i++;
        cout << "1 ";
    }
    while (two--)
    {
        arr[i] = 2;
        i++;
        cout << "2 ";
    }

    return 0;
}