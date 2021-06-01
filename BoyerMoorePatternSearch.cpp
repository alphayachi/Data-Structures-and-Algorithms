#include <bits/stdc++.h>
using namespace std;

#define MAX_CHARS 256

void badCharHeuristic(string str, int size, int badChar[MAX_CHARS])
{
    for (int i = 0; i < MAX_CHARS; i++)
        badChar[i] = -1;
    for (int i = 0; i < size; i++)
        badChar[(int)str[i]] = i;
}

void searchPattern(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int badChar[MAX_CHARS];

    badCharHeuristic(pat, m, badChar);

    int s = 0; // s represents the first element of the text window
    //we are comparing the pattern to.
    while (s <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            cout << "Pattern found at " << s << endl;
            s += (s + m < n) ? m - badChar[(int)txt[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badChar[(int)txt[s + j]]);
        }
    }
}

int main()
{
    string txt = "ABAAABCD";
    string pat = "ABC";
    searchPattern(txt, pat);
    return 0;
    return 0;
}