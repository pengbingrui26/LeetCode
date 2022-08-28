#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Solution1
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_map<int, int> HashList;
        for (int i = 0; i < nums.size(); i++)
        {
            if (HashList.find(nums[i]) == HashList.end())
            {
                HashList[nums[i]] = 1;
            }
            else if (HashList[nums[i]] >= 2)
            {
                return 1;
            }
            else
            {
                HashList[nums[i]]++;
            }
        }
        bool tr = 0;
        for (auto it = HashList.begin(); it != HashList.end(); it++)
        {
            if (it->second >= 2)
            {
                tr = 1;
                break;
            }
        }
        return tr;
    }
};

class Solution2
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_map<int, int> HashList;
        bool tr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (HashList.find(nums[i]) != HashList.end())
            {
                bool tr = 1;
                return tr;
            }
            HashList[nums[i]] = 1;
        }
        return tr;
    }
};

// =======================================================================

void test02()
{
    Solution2 solution;
    std::vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4};
    auto tr = solution.containsDuplicate(nums);
    std::cout << tr << std::endl;
}

// =======================================================================

int main()
{
    test02();
}
