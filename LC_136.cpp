#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void print(std::unordered_map<int, int> &HashList)
{
    for (auto it = HashList.begin(); it != HashList.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

// Hash

class Solution1
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        std::unordered_map<int, int> HashList;
        for (int i = 0; i < nums.size(); i++)
        {
            if (HashList.find(nums[i]) != HashList.end())
            {
                HashList[nums[i]] += 1;
            }
            else
            {
                HashList[nums[i]] = 1;
            }
        }
        print(HashList);
        int output;
        for (auto it = HashList.begin(); it != HashList.end(); it++)
        {
            if (it->second == 1)
            {
                output = it->first;
                break;
            }
        }
        return output;
    }
};

// =================================================================

void test01()
{
    Solution1 solution;
    std::vector<int> vv = {4, 1, 2, 1, 2};
    auto oo = solution.singleNumber(vv);
    std::cout << oo << std::endl;
}

// =================================================================

int main()
{
    test01();
}