// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends

int maxAreaofHist(int hist[], int m)
{
    vector<int> left(m), right(m);
    stack<int> s;
    for (int i = 0; i < m; i++)
    {
        if (s.empty())
        {
            left[i] = 0;
            s.push(i);
        }
        else
        {
            while (!s.empty() && hist[s.top()] >= hist[i])
            {
                s.pop();
            }
            left[i] = s.empty() ? 0 : s.top() + 1;
            s.push(i);
        }
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (int i = m - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            right[i] = m - 1;
            s.push(i);
        }
        else
        {
            while (!s.empty() && hist[s.top()] >= hist[i])
            {
                s.pop();
            }
            right[i] = s.empty() ? m - 1 : s.top() - 1;
            s.push(i);
        }
    }

    int mxarea = -1;
    for (int i = 0; i < m; i++)
    {
        mxarea = max(mxarea, hist[i] * (right[i] - left[i] + 1));
    }
    return mxarea;
}

/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m)
{

    int hist[m] = {0};
    int maxArea = -1;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if (M[r][c] == 0)
            {
                hist[c] = 0;
            }
            else
            {
                hist[c] += M[r][c];
            }
        }
        int area = maxAreaofHist(hist, m);
        if (area > maxArea)
        {
            maxArea = area;
        }
    }
    return maxArea;
}
