#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int BSpivot(vector<int> nums, int l, int r)
    {
        if (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid == nums.size() - 1)
                return mid;
            if (nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] < nums[mid + 1])
            {
                if (nums[mid] < nums[0])
                    return BSpivot(nums, l, mid - 1);
                else
                    return BSpivot(nums, mid + 1, r);
            }
        }
        return -1;
    }

    int BStarget(vector<int> nums, int l, int r, int target)
    {
        if (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                return BStarget(nums, mid + 1, r, target);
            else
                return BStarget(nums, l, mid - 1, target);
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int r = nums.size() - 1;
        int pivot = BSpivot(nums, 0, r);
        int find_left = BStarget(nums, 0, pivot, target);
        int find_right = BStarget(nums, pivot + 1, r, target);
        if (find_left > find_right)
            return find_left;
        else
            return find_right;
    }
};

int main()
{
    return 0;
}