#include <bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }
        else
        {
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    return -1;
}

vector<int> find(int arr[], int n, int x)
{
    vector<int> ans;

    int mark = binarySearch(arr, 0, n - 1, x);

    if (mark == -1)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    int l = mark, r = mark;
    while (arr[l] == x)
    {
        l--;
    }
    while (arr[r] == x)
    {

        r++;
    }
    l++;
    r--;
    ans.push_back(l);
    ans.push_back(r);

    return ans;
}