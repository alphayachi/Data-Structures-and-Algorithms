#include <bits/stdc++.h>
using namespace std;

int split(string s)
{
    int n = s.length();
    int one = 0, zero = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if ((zero != one || zero == 0 || one == 0) && s[i] == '0')
        {

            zero++;

            if (zero == one && zero != 0 && one != 0)
            {
                ans++;
                zero = 0;
                one = 0;
            }
        }
        else if ((zero != one || zero == 0 || one == 0) && s[i] == '1')
        {

            one++;

            if (zero == one && zero != 0 && one != 0)
            {
                ans++;
                zero = 0;
                one = 0;
            }
        }
    }

    if (zero != 0 || one != 0)
    {
        ans = -1;
        return ans;
    }
    else
    {
        return ans;
    }
}

int main()
{

    string s = "0111100010";

    int ans = split(s);

    cout << ans << endl;

    return 0;
}