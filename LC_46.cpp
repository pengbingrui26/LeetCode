#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>

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
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return {{nums[0]}};
        }
        else
        {
            std::vector<std::vector<int>> output;
            std::vector<int> nums_last(nums.begin(), nums.end() - 1);
            int tail = nums[nums.size() - 1];
            auto last = permute(nums_last);
            for (auto v : last)
            {
                for (int i = 0; i <= v.size(); i++)
                {
                    std::vector<int> tmp = v;
                    tmp.insert(tmp.begin() + i, tail);
                    output.push_back(tmp);
                }
            }
            return output;
        }
    }
};

int main()
{
}