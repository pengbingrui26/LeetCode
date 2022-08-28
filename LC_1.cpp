#include <iostream>
#include <vector>
#include <unordered_map>

class Solution1
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::vector<int> res;
        bool find = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    find = 1;
                    break;
                }
            }
            if (find)
            {
                break;
            }
        }
        return res;
    }
};

// Hash

class Solution2
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> HashList;
        for (int i = 0; i < nums.size(); i++)
        {
            auto p = HashList.find(target - nums[i]);
            if (p != HashList.end())
            {
                return {i, p->second};
            }
            HashList[nums[i]] = i;
        }
    }
};

class Solution3
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> HashList;
        for (int i = 0; i < nums.size(); i++)
        {
            // HashList[nums[i]] = i;
            HashList.insert(std::make_pair(nums[i], i));
        }
        std::vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            auto p = HashList.find(target - nums[i]);
            if (p != HashList.end() && p->second != i)
            {
                res.push_back(i);
                res.push_back(p->second);
                break;
            }
        }
        return res;
    }
};

// =======================================================

void test01()
{
    std::vector<int> vv = {2, 7, 11, 15};
    int sum = 9;
    Solution1 solution;
    auto output = solution.twoSum(vv, sum);
    std::cout << output[0] << output[1] << std::endl;
}

void test02()
{
    std::vector<int> vv = {2, 7, 11, 15};
    int sum = 9;
    Solution2 solution;
    auto output = solution.twoSum(vv, sum);
    std::cout << output[0] << output[1] << std::endl;
}

void test03()
{
    std::vector<int> vv = {3, 2, 4};
    int sum = 6;
    Solution3 solution;
    auto output = solution.twoSum(vv, sum);
    std::cout << output[0] << output[1] << std::endl;
}

// =======================================================

int main()
{
    // test01();
    // test02();
    test03();
}