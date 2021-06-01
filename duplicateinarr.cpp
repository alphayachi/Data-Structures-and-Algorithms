#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int ans;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums.at(i) == nums.at(i - 1))
        {
            ans = nums.at(i);
        }
    }
    return ans;
}

int main()
{
    return 0;
}