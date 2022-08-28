#include <iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int this_profit = 0;
        int max_profit = 0;
        // int day_buy = 0;
        if (prices.size() <= 1)
        {
            return 0;
        }
        for (int i = 1; i < prices.size(); i++)
        {
            this_profit += (prices[i] - prices[i - 1]);
            if (this_profit > max_profit)
            {
                max_profit = this_profit;
            }
            if (this_profit <= 0)
            {
                this_profit = 0;
            }
        }
        return std::max(0, max_profit);
    }
};

// ===============================================================================

int main()
{
}
