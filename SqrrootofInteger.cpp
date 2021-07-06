// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long int BS(int N, int l, int r)
    {
        if (l <= r)
        {
            long long int mid = l + (r - l) / 2;
            if (mid * mid <= N && (mid + 1) * (mid + 1) > N)
            {
                if (mid * mid == N)
                    return mid - 1;
                else
                    return mid;
            }
            else
            {
                if (mid * mid > N)
                    return BS(N, l, mid - 1);
                else
                    return BS(N, mid + 1, r);
            }
        }
        return 0;
    }

    int countSquares(int N)
    {
        long long int ans = BS(N, 1, N / 2);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
} // } Driver Code Ends