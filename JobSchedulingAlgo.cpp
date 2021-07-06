#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int start, finish, value;
};

int sortingCompare(Job a, Job b)
{
    return (a.finish < b.finish);
}

int lastPossibleJob(Job jobs[], int i, int low, int high)
{
    //find using binary Search
    int mid = low + (high - low) / 2;
    if (low > high)
    {
        return -1;
    }
    if (jobs[mid].finish <= jobs[i].start && jobs[mid + 1].finish > jobs[i].start)
    {
        return mid;
    }
    else if (jobs[mid].finish > jobs[i].start)
    {
        return lastPossibleJob(jobs, i, low, mid - 1);
    }
    else if (jobs[mid].finish < jobs[i].start && jobs[mid + 1].finish > jobs[i].start)
    {
        return lastPossibleJob(jobs, i, mid + 1, high);
    }
    return -1;
}

int scheduler(Job jobs[], int n)
{
    sort(jobs, jobs + n, sortingCompare);

    int dp[n];
    dp[0] = jobs[0].value;
    for (int i = 1; i < n; i++)
    {
        int profit = jobs[i].value;
        int lastjob = lastPossibleJob(jobs, i, 0, i - 1);
        int included_profit = profit + dp[lastjob];
        dp[i] = max(included_profit, dp[i - 1]);
    }
    return dp[n - 1];
}

int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Optimal profit is " << scheduler(arr, n);

    return 0;
}