#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution1
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        std::unordered_map<int, int> HashList;
        // std::vector<int> HashList;
        for (int i = 0; i < nums.size(); i++)
        {
            if (HashList.find(nums[i]) == HashList.end())
            {
                HashList[nums[i]] = 1;
            }
            else
            {
                HashList[nums[i]]++;
            }
        }
        int N = nums.size() / 2;
        int res;
        for (auto it = HashList.begin(); it != HashList.end(); it++)
        {
            if (it->second > N)
            {
                res = it->first;
                break;
            }
        }
        return res;
    }
};

class Solution2
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// =================================================================

void test01()
{
    Solution1 solution;
    std::vector<int> vv = {4, 1, 2, 1, 2};
    auto oo = solution.majorityElement(vv);
    std::cout << oo << std::endl;
}

void test02()
{
    Solution2 solution;
    std::vector<int> vv = {4, 1, 1, 1, 2};
    auto oo = solution.majorityElement(vv);
    std::cout << oo << std::endl;
}

// =================================================================

int main()
{
    // test01();
    test02();
}
