#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int a, b;
        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
            {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            }
            else
            {
                b = abs(arr[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                a = i + 1;
                break;
            }
        }
        int *ans = new int(2);
        ans[0] = b;
        ans[1] = a;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}