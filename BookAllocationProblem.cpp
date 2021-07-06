#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int mid, int n, int m)
{
    int studentsreq = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }

        if (sum + arr[i] > mid)
        {
            studentsreq++;
            sum = arr[i];
            if (studentsreq > m)
                return false;
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

class Solution
{
public:
    int findPages(int arr[], int n, int m)
    {
        int end = 0;
        if (n < m)
            return -1;
        for (int i = 0; i < n; i++)
        {
            end += arr[i];
        }
        int ans = INT_MAX;
        int start = 0;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (isPossible(arr, mid, n, m))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
