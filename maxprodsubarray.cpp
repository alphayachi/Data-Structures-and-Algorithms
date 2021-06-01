// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(int *arr, int n)
    {
        long long int max_overall = arr[0], max_ending_here = arr[0], min_ending_here = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
            {
                swap(max_ending_here, min_ending_here);
            }
            max_ending_here = max((long long int)arr[i], max_ending_here * arr[i]);
            min_ending_here = min((long long int)arr[i], min_ending_here * arr[i]);
            if (max_overall < max_ending_here)
            {
                max_overall = max_ending_here;
            }
        }
        return max_overall;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends