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
private:
    int prod(std::vector<int> &nums, int i, int j)
    {
        /*if (i == j)
            return nums[i]
        else {*/
        int tot = 1;
        for (int k = i; k <= j; k++)
            tot *= nums[k];
        return tot;
    }

public:
    int maxProduct(std::vector<int> &nums)
    {
        int N = nums.size();
        std::vector<std::vector<int>> hashlist(N, std::vector<int>(N));
        std::vector<std::pair<int, int>> arrs;
        hashlist[0][0] = prod(nums, 0, 0);
        // arrs.push_back(std::make_pair(0, 0));
        int maxprod = hashlist[0][0];
        if (N == 1)
            return maxprod;
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                // arrs.push_back(std::make_pair(j, i));
                if (j < i)
                    hashlist[j][i] = hashlist[j][i - 1] * nums[i];
                else
                    hashlist[j][i] = nums[i];
                if (hashlist[j][i] > maxprod)
                    maxprod = hashlist[j][i];
            }
        }
        return maxprod;
    }
};

// ==============================================================

void test01()
{
    std::vector<int> nums = {-2, 0, -1};
    Solution solution;
    auto it = solution.maxProduct(nums);
    std::cout << it << std::endl;
}

// ==============================================================

int main()
{
    test01();
}