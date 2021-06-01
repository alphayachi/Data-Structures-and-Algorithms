// { Driver Code Starts
#include <iostream>
#include <string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << PalinArray(a, n) << endl;
    }
} // } Driver Code Ends

bool palin(int num)
{
    int digits = 0;
    int temp = num;
    int numarr[100000];
    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }
    temp = num;
    for (int i = digits - 1; i >= 0; i--)
    {
        numarr[i] = temp % 10;
        temp /= 10;
    }
    int i = 0, j = digits - 1;
    while (i <= j)
    {
        if (numarr[i] != numarr[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

/*Complete the function below*/
int PalinArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!palin(a[i]))
        {
            break;
        }
    }
    if (i == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}