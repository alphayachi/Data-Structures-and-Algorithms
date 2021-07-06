#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        pair<int, int> record[n];
        for (int i = 0; i < n; i++)
        {
            record[i].first = nums[i];
            record[i].second = i;
        }
        sort(record, record + n);
        vector<bool> visited(n, false);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] || record[i].second == i)
                continue;
            int j = i;
            int cyclesize = 0;
            while (!visited[j])
            {
                visited[j] = true;
                j = record[j].second;
                cyclesize++;
            }
            ans += cyclesize - 1;
        }
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
}