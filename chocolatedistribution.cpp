#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int m;
        cin >> m;

        sort(a, a + n);
        int mindiff = INT_MAX;
        for (int i = 0; i <= n - m; i++)
        {
            int diff = a[i + m - 1] - a[i];
            if (mindiff > diff)
            {
                mindiff = diff;
            }
        }
        cout << mindiff << endl;
    }

    return 0;
}