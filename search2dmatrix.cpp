#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int BSR(vector<int> high, int target, int lo, int hi)
    {
        if (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (high[mid] == target)
            {
                return mid;
            }
            if (high[mid] > target)
            {
                if (mid > 0 && high[mid - 1] < target)
                {
                    return mid;
                }
                if (mid > 0 && high[mid - 1] >= target)
                {
                    return BSR(high, target, lo, mid - 1);
                }
                if (mid == 0)
                {
                    return mid;
                }
            }
            if (high[mid] < target)
            {
                return BSR(high, target, mid + 1, hi);
            }
        }
        return -1;
    }

    bool BS(vector<int> row, int target, int lo, int hi)
    {
        if (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (row[mid] == target)
            {
                return true;
            }
            if (row[mid] > target)
            {
                return BS(row, target, lo, mid - 1);
            }
            if (row[mid] < target)
            {
                return BS(row, target, mid + 1, hi);
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int colcount = matrix[0].size();
        int rowcount = matrix.size();
        vector<int> high;
        for (int i = 0; i < rowcount; i++)
        {
            high.push_back(matrix[i][colcount - 1]);
        }
        int rowselect;
        rowselect = BSR(high, target, 0, rowcount - 1);
        bool ans;
        if (rowselect >= 0)
        {
            ans = BS(matrix[rowselect], target, 0, colcount - 1);
        }
        else
        {
            ans = false;
        }
        return ans;
    }
};

int main()
{
    return 0;
}