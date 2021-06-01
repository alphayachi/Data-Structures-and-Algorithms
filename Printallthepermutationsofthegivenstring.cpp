// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void permutate(string a, int l, int r, vector<string> &vect)
    {

        if (l == r)
            vect.push_back(a);
        else
        {

            for (int i = l; i <= r; i++)
            {
                swap(a[l], a[i]);
                permutate(a, l + 1, r, vect);
                swap(a[l], a[i]);
            }
        }
    }

    void permute(string str, int n, vector<string> &vect)
    {
        sort(str.begin(), str.end());
        vect.push_back(str);

        while (next_permutation(str.begin(), str.end()))
        {
            vect.push_back(str);
        }
    }

    vector<string> find_permutation(string S)
    {
        vector<string> permutations;
        int r = S.length();
        permute(S, r, permutations);
        return permutations;
    }

    //// USE next_permutation() for solving....this just gives all the permutations but not in lexicographical order
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends