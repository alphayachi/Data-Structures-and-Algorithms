// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        int i = 0, j = 0;
        vector<int> common;
        while (i < n1 && j < n2)
        {
            if (A[i] < B[j])
            {
                i++;
            }
            else if (B[j] < A[i])
            {
                j++;
            }
            else if (A[i] == B[j])
            {
                if (common.size() > 0 && common.back() == A[i])
                {
                    i++;
                    j++;
                    continue;
                }
                common.push_back(A[i]);
                i++;
                j++;
            }
        }
        int n4 = common.size();
        i = 0;
        j = 0;
        vector<int> common1;
        while (i < n4 && j < n3)
        {
            if (C[j] < common.at(i))
            {
                j++;
            }
            else if (C[j] > common.at(i))
            {
                i++;
            }
            else if (C[j] == common.at(i))
            {
                if (common1.size() > 0 && common.at(i) == common1.back())
                {
                    i++;
                    j++;
                    continue;
                }
                common1.push_back(C[j]);
                i++;
                j++;
            }
        }
        return common1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends