// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n)
{
    if (n <= 1)
    {
        return 0;
    }
    if (arr[0] == 0)
    {
        return -1;
    }
    int ladder = arr[0];
    int stairs = arr[0];
    int jump = 1;
    for (int level = 1; level < n; level++)
    {
        if (level == n - 1)
        {
            return jump;
        }
        if (arr[level] == 0 && ladder == level)
        {
            return -1;
        }
        if (level + arr[level] > ladder)
        {
            ladder = level + arr[level];
        }

        stairs--;
        if (stairs == 0)
        {
            jump++;
            stairs = ladder - level;
        }
    }
    return jump;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends