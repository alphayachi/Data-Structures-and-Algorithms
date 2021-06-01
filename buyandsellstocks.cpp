#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (minprice > prices.at(i))
            {
                minprice = prices.at(i);
            }
            else if (maxprofit < prices.at(i) - minprice)
            {
                maxprofit = prices.at(i) - minprice;
            }
        }
        return maxprofit;
    }
};

int main()
{
    return 0;
}