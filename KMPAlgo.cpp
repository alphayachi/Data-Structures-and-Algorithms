#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //KMP PATTERN SEARCH ALGO AFTER PREPROCESSING:
    bool KMP(char *pat, char *text)
    {
        int m = strlen(pat);
        int n = strlen(text);
        int lpsArr[m];
        efflps(pat, m, lpsArr);
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (pat[j] == text[i])
            {
                j++;
                i++;
            }

            if (j == m)
            {
                return true;
            }
            else if (i < n && pat[j] != text[i])
            {
                if (j != 0)
                {
                    j = lpsArr[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return false;
    }

    //preprocessing for kmp .... we use lps > longest proper prefix/suffix

    ///better lps:
    void efflps(char *pat, int m, int *lpsArr)
    {
        int i = 0, j = 1;
        lpsArr[0] = 0;
        while (j < m)
        {
            if (pat[i] == pat[j])
            {
                lpsArr[j] = i + 1;
                i++;
                j++;
            }
            else
            {
                if (i != 0)
                {
                    i = lpsArr[j - 1];
                }
                else
                {
                    lpsArr[j] = 0;
                    j++;
                }
            }
        }
    }

    int lps(string s)
    {
        int n = s.length();
        int suff = 1;
        int pref = 0;
        for (int suff = 1; suff < n; suff++)
        {
            if (s[pref] != s[suff])
            {
                if (pref != 0)
                {
                    suff = suff - pref;
                }
                pref = 0;
            }
            else
            {
                pref++;
            }
        }
        pref--;
        if (s[0] == s[n - pref - 1])
        {
            return pref + 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}