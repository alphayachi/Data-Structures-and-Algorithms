
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispar(string x)
    {
        stack<char> s;
        for (int i = 0; i < x.length(); i++)
        {
            switch (x[i])
            {
            case '{':
                s.push('{');
                break;
            case '[':
                s.push('[');
                break;
            case '(':
                s.push('(');
                break;
            case '}':
                if (!s.empty() && s.top() == '{')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ')':
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                break;
            default:
                cout << "wrong values entered";
            }
        }
        if (s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}