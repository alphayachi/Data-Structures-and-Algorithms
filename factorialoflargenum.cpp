#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &ans, int num)
{
    int rem = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        int prod = ans.at(i) * num + rem;
        ans.at(i) = prod % 10;
        rem = prod / 10;
    }
    while (rem > 0)
    {
        ans.push_back(rem % 10);
        rem = rem / 10;
    }
    return;
}

void factorial(int n)
{
    vector<int> ans;
    ans.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        multiply(ans, i);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans.at(i);
    }
    cout << endl;
    return;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        factorial(n);
    }
    return 0;
}