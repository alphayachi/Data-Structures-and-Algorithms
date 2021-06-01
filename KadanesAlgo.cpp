// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n)
{
    int maxendinghere = 0;
    int maxsofar = 0;
    for (int i = 0; i < n; i++)
    {
        maxendinghere += arr[i];
        if (maxendinghere < 0)
        {
            maxendinghere = 0;
        }
        if (maxendinghere > maxsofar)
        {
            maxsofar = maxendinghere;
        }
    }
    if (maxsofar == 0)
    {
        maxsofar = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maxsofar)
            {
                maxsofar = arr[i];
            }
        }
    }
    return maxsofar;
}

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends