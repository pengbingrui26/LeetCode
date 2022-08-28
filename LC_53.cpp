#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int this_sum = 0;
        int maxsum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            this_sum += nums[i];
            if (this_sum > maxsum)
                maxsum = this_sum;
            if (this_sum < 0)
                this_sum = 0;
        }
        return maxsum;
    }
};

int main()
{
}
