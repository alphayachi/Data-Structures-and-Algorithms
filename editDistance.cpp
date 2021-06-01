#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int editDistance(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        int dp[2][m + 1];

        memset(dp, 0, sizeof dp);

        for (int i = 0; i <= m; i++)
            dp[0][i] = i;

        for (int i = 1; i <= n; i++)
        {

            for (int j = 0; j <= m; j++)
            {

                if (j == 0)
                    dp[i % 2][j] = i;

                else if (s[j - 1] == t[i - 1])
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                }

                // if character from both string is
                // not same then we take the minimum
                // from three specified operation
                else
                {
                    dp[i % 2][j] = 1 + min(dp[(i - 1) % 2][j],
                                           min(dp[i % 2][j - 1],
                                               dp[(i - 1) % 2][j - 1]));
                } // characters
            }
        }

        return dp[n % 2][m];
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
