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
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return (nums[0] >= nums[1]) ? nums[0] : nums[1];

        std::vector<int> hashlist(nums.size());
        hashlist[0] = nums[0];
        hashlist[1] = (nums[0] >= nums[1]) ? nums[0] : nums[1];

        for (int i = 2; i < nums.size(); i++)
        {
            hashlist[i] = (hashlist[i - 2] + nums[i] > hashlist[i - 1]) ? (hashlist[i - 2] + nums[i]) : hashlist[i - 1];
        }
        return hashlist[nums.size() - 1];
    }
};

int main()
{
}