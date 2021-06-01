#include <bits/stdc++.h>
using namespace std;

int countRev(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';
    }
}

int countRev(string bracketString)
{
    int len = bracketString.length();

    if (len % 2)
        return -1;

    stack<char> s;
    for (int i = 0; i < len; i++)
    {
        if (bracketString[i] == '}' && !s.empty())
        {
            if (s.top() == '{')
                s.pop();
            else
                s.push(bracketString[i]);
        }
        else
            s.push(bracketString[i]);
    }

    int leftout_length = s.size();

    int n = 0;
    while (!s.empty() && s.top() == '{')
    {
        s.pop();
        n++;
    }

    return (leftout_length / 2 + n % 2);
}