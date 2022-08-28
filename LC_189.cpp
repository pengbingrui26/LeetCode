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

class Solution1
{
private:
    void jump1(std::vector<int> &nums)
    {
        int tail = nums.back();
        nums.pop_back();
        nums.insert(nums.begin(), tail);
    }
    void jump2(std::vector<int> &nums)
    {
        int head = nums[0];
        nums.erase(nums.begin());
        nums.insert(nums.end(), head);
    }

public:
    void rotate(std::vector<int> &nums, int k)
    {
        k = k % nums.size();
        if (k == 0)
            return;
        if (k <= nums.size() / 2)
        {
            for (int r = 0; r < k; r++)
                jump1(nums);
        }
        else
        {
            for (int r = 0; r < nums.size() - k; r++)
                jump2(nums);
        }
    }
};

class Solution2
{
public:
    void rotate(std::vector<int> &nums, int k)
    {
        k = k % nums.size();
        if (k == 0)
            return;
        std::vector<int> nums_new(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            nums_new[i] = nums[(i + nums.size() - k) % nums.size()];
        }
        nums = nums_new;
    }
};

int main()
{
}