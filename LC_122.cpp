#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
#include <tuple>
#include <map>

void print(std::vector<int> &v)
{
    for (auto it : v)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        std::vector<int> extremes;
        for (int i = 1; i < prices.size() - 1; i++)
        {
            if (prices[i] >= prices[i - 1] && prices[i] >= prices[i + 1])
                extremes.push_back(i);
        }
        // std::cout << extremes.size() << std::endl;
        if (extremes.size() == 0)
        {
            // std::cout << "0" << std::endl;
            // int minval = *std::min_element(prices.begin(), prices.end());
            // int maxval = *std::max_element(prices.begin(), prices.end());
            // return maxval - minval;
            int this_profit = 0;
            int max_profit = 0;
            for (int k = 1; k < prices.size(); k++)
            {
                this_profit += (prices[k] - prices[k - 1]);
                if (this_profit > max_profit)
                    max_profit = this_profit;
                if (this_profit < 0)
                    this_profit = 0;
            }
            return max_profit;
        }
        else
        {
            extremes.push_back(prices.size() - 1);
            int profit = 0;
            int idx_last = 0;
            for (auto idx : extremes)
            {
                int minval = *std::min_element(prices.begin() + idx_last, prices.begin() + idx + 1);
                // int maxval = *std::max_element(prices.begin()+idx_last, prices.begin()+idx+1);
                profit += (prices[idx] - minval);
                idx_last = idx;
            }
            return profit;
        }
    }
};

int main()
{
}