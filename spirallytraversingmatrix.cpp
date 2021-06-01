// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        vector<int> list;
        int i, k = 0, l = 0;
        while (k < r && l < c)
        {
            for (i = l; i < c; i++)
            {
                list.push_back(matrix[k][i]);
            }
            k++;
            for (i = k; i < r; i++)
            {
                list.push_back(matrix[i][c - 1]);
            }
            c--;
            if (k < r)
            {
                for (i = c - 1; i >= l; i--)
                {
                    list.push_back(matrix[r - 1][i]);
                }
                r--;
            }
            if (l < c)
            {
                for (i = r - 1; i >= k; i--)
                {
                    list.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return list;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends