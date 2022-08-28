#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>

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
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        if (nums.size() == 1)
        {
            if (nums[0] == target)
                return {0, 0};
            else
                return {-1, -1};
        }
        int left = 0;
        int right = nums.size() - 1;
        int m = (left + right) / 2;
        while (left <= right)
        {
            if (nums[m] > target)
            {
                right = m - 1;
                m = (left + right) / 2;
            }
            else if (nums[m] < target)
            {
                left = m + 1;
                m = (left + right) / 2;
            }
            else
                break;
        }
        if (nums[m] != target)
        {
            return {-1, -1};
        }
        else
        {
            int front = m;
            int hind = m;
            while (front >= 0)
            {
                if (nums[front] != target)
                    break;
                front--;
            }
            while (hind < nums.size())
            {
                if (nums[hind] != target)
                    break;
                hind++;
            }
            return {front + 1, hind - 1};
        }
    }
};

int main()
{
}