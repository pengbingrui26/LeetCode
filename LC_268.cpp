#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <set>

class Solution1
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int re = nums.size();
        int i = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                re = i;
                break;
            }
        }
        return re;
    }
};

class Solution2
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        std::set<int> HashList;
        for (int i = 0; i < nums.size(); i++)
        {
            HashList.insert(nums[i]);
        }
        int missed;
        for (int k = 0; k <= nums.size(); k++)
        {
            if (HashList.find(k) == HashList.end())
            {
                missed = k;
                break;
            }
        }
        return missed;
    }
};

// ============================================================================

void test01()
{
}

// ============================================================================

int main()
{
}
