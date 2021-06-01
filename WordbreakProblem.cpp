#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        cout << wordBreak(line, dict) << "\n";
    }
}

int wordBreak(string A, vector<string> &B)
{
    int n = A.length();
    int dp[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            //cout<<A.substr(j,i-j+1)<<" ";
            for (int k = 0; k < B.size(); k++)
            {
                if (A.substr(j, i - j + 1) == B.at(k))
                {
                    if (j > 0)
                    {
                        dp[i] += dp[j - 1];
                    }
                    else
                    {
                        dp[i] += 1;
                    }
                    break;
                }
            }
        }
        // cout<<dp[i]<<endl;
    }
    //cout<<endl;
    return dp[n - 1];
}