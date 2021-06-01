#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}

int romanEval(char r)
{
    switch (r)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        cout << "default error" << endl;
        break;
    }
    return -1;
}

int romanToDecimal(string &str)
{
    int n = str.length();
    int decval = 0;
    int prev = 1500;
    for (int i = 0; i < n; i++)
    {
        int currval = romanEval(str[i]);
        if (prev < currval)
            decval = decval - (2 * prev) + currval;
        else
            decval += currval;
        prev = currval;
    }
    return decval;
}