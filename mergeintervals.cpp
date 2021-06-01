#include <bits/stdc++.h>
using namespace std;

bool compareIntervals(vector<int> a, vector<int> b)
{
    return (a.at(0) < b.at(0));
}
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compareIntervals);
        vector<vector<int>> merged;
        merged.push_back(intervals.at(0));
        int j = 0;
        int i = 0;
        while (i != intervals.size())
        {
            if (merged.at(j).at(1) < intervals.at(i).at(0))
            {
                merged.push_back(intervals.at(i));
                i++;
                j++;
            }
            else
            {
                if (merged.at(j).at(1) < intervals.at(i).at(1))
                {
                    merged.at(j).at(1) = intervals.at(i).at(1);
                    i++;
                }
                else
                {
                    i++;
                }
            }
        }
        return merged;
    }
};

int main()
{
    return 0;
}