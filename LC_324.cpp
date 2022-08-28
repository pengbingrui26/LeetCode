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
    void wiggleSort(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<int> nums_new;
        if (nums.size() % 2 == 0)
        {
            for (int i = nums.size() / 2 - 1; i >= 0; i--)
            {
                nums_new.push_back(nums[i]);
                nums_new.push_back(nums[i + nums.size() / 2]);
            }
        }
        else
        {
            for (int i = nums.size() / 2; i >= 1; i--)
            {
                nums_new.push_back(nums[i]);
                nums_new.push_back(nums[i + nums.size() / 2]);
            }
            nums_new.push_back(nums[0]);
        }
        nums = nums_new;
    }
};

int main()
{
}