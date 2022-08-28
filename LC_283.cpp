#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <set>

void print(std::vector<int> vv)
{
    for (int i = 0; i < vv.size(); i++)
    {
        std::cout << vv[i] << " ";
        std::cout << std::endl;
    }
}

class Solution1
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0)
            {
                int k;
                for (int j = i + 1; j < nums.size(); j++)
                {
                    k = j;
                    if (nums[j] != 0)
                    {
                        break;
                    }
                }
                int tmp = nums[k];
                nums[i] = tmp;
                nums[k] = 0;
            }
        }
    }
};

// ===========================================================

void test01()
{
    Solution1 solution;
    std::vector<int> nums = {0, 0, 1, 100, 3, 0, 12};
    solution.moveZeroes(nums);
    print(nums);
}

// ===========================================================

int main()
{
    test01();
}