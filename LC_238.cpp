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

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> output;
        int prod = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            prod *= nums[i];
        }
        output.push_back(prod);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                prod *= nums[i - 1];
                prod /= nums[i];
                output.push_back(prod);
            }
            else
            {
                int tmp = 1;
                for (int k = 0; k < nums.size(); k++)
                {
                    if (k == i)
                        continue;
                    tmp *= nums[k];
                }
                prod = tmp;
                output.push_back(prod);
            }
        }
        return output;
    }
};

int main()
{
}