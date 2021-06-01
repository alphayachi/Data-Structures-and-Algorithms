#include <bits/stdc++.h>
using namespace std;

#define d 256

vector<int> patsearch(char *txt, char *pat)
{
    int q = 1193;
    int M = strlen(pat);
    int N = strlen(txt);
    int p = 0, t = 0, h = 1;
    vector<int> ans;

    for (int i = 0; i < M - 1; i++)
    {
        h = (h * d) % q;
    }
    for (int i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            int j;
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == M)
            {
                ans.push_back(i);
            }
        }
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
    return ans;
}

int main()
{

    // char text[1000];
    // cin.getline(text, 1000);
    // char pat[100];
    // cin.getline(pat, 100);
    char text[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";

    vector<int> ans = patsearch(text, pat);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}