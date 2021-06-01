// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int isPlaindrome(string S)
    {
        int left = 0, right = S.length() - 1;
        int check = 1;
        while (left <= right)
        {
            if (S[left] != S[right])
            {
                check = 0;
                break;
            }
            left++;
            right--;
        }
        return check;
    }
};

// { Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.isPlaindrome(s) << "\n";
    }

    return 0;
} // } Driver Code Ends