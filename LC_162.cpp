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
    int findPeakElement(std::vector<int> &nums)
    {
        // nums.insert(nums.begin(), -INT_MAX);
        // nums.insert(nums.end(), -INT_MAX);
        if (nums.size() == 1)
            return 0;
        /*if (nums.size() == 2){
            if (nums[0] > nums[1])
                return 0;
            else if (nums[0] < nums[1])
                return 1;
        }*/
        if (nums[0] > nums[1])
            return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
                return i;
        }
        return -1;
    }
};

int main()
{
}