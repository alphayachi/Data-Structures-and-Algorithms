// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x);

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << sb(a, n, x) << endl;
    }
    return 0;
} // } Driver Code Ends

int sb(int arr[], int n, int x)
{
    int start = 0, end = 0;
    int length = 0, sum = 0;
    while (sum <= x)
    {
        sum += arr[end];
        end++;
    }
    length = end - start;
    while (end <= n)
    {
        if (sum <= x)
        {
            if (end == n)
            {
                break;
            }
            sum += arr[end];
            end++;
            if (end - start < length)
            {
                length = end - start;
            }
            continue;
        }
        sum -= arr[start];
        start++;
        if (sum > x)
        {
            if (end - start < length)
            {
                length = end - start;
            }
            continue;
        }
    }
    return length;
}