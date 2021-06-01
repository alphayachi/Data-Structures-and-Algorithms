// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int mx = max(arr1[n - 1], arr2[m - 1]);
        mx++;
        int i = 0, j = 0, k = 0;
        while (i < n && j < m && k < (n + m))
        {
            int e1 = arr1[i] % mx;
            int e2 = arr2[j] % mx;
            if (e1 <= e2)
            {
                if (k < n)
                {
                    arr1[k] += e1 * mx;
                    i++;
                    k++;
                }
                else
                {
                    arr2[k - n] += e1 * mx;
                    i++;
                    k++;
                }
            }
            else
            {
                if (k < n)
                {
                    arr1[k] += e2 * mx;
                    j++;
                    k++;
                }
                else
                {
                    arr2[k - n] += e2 * mx;
                    j++;
                    k++;
                }
            }
        }
        while (i < n && k < (n + m))
        {
            int e1 = arr1[i] % mx;
            if (k < n)
            {
                arr1[k] += e1 * mx;
                i++;
                k++;
            }
            else
            {
                arr2[k - n] += e1 * mx;
                i++;
                k++;
            }
        }
        while (j < m && k < (n + m))
        {
            int e2 = arr2[j] % mx;
            if (k < n)
            {
                arr1[k] += e2 * mx;
                j++;
                k++;
            }
            else
            {
                arr2[k - n] += e2 * mx;
                j++;
                k++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr1[i] = arr1[i] / mx;
        }
        for (int j = 0; j < m; j++)
        {
            arr2[j] = arr2[j] / mx;
        }
        return;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends