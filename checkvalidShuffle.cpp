#include <bits/stdc++.h>
using namespace std;

bool checkInterleaved(char *a, char *b, char *c)
{
    int l1 = strlen(a);
    int l2 = strlen(b);

    bool dp[l1 + 1][l2 + 1];
    memset(dp, 0, sizeof(dp));

    if (l1 + l2 != strlen(c))
        return false;

    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {

            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                if (b[j - 1] == c[j - 1])
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
            else if (j == 0)
            {
                if (a[i - 1] == c[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else if (a[i - 1] == c[i + j - 1] && b[j - 1] != c[i + j - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (b[j - 1] == c[i + j - 1] && a[i - 1] != c[i + j - 1])
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (a[i - 1] == c[i + j - 1] && b[j - 1] == c[i + j - 1])
            {
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    return 0;
}