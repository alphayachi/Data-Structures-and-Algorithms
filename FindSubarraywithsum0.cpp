#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    ll findSubarray(vector<ll> arr, int n)
    {
        long long int count = 0;
        unordered_map<long long int, long long int> sums;
        sums[0] = 1;
        long long int sumtillnow;
        for (int i = 0; i < n; i++)
        {
            sumtillnow += arr[i];
            if (sums.find(sumtillnow) != sums.end())
            {
                count += sums[sumtillnow];
                sums[sumtillnow]++;
            }
            else
            {
                sums[sumtillnow] = 1;
            }
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; //input size of array

        vector<ll> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
}