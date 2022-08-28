#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>

void print(std::vector<int> &v)
{
    for (auto it : v)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

class Solution1
{
public:
    bool canJump(std::vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        bool tr = 1;
        int zero_pos = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            std::cout << "i: " << i << std::endl;
            if (nums[i] == 0)
            {
                bool can = 0;
                for (int j = 0; j < i; j++)
                {
                    if (j + nums[j] > i)
                    {
                        can = 1;
                        break;
                    }
                }
                if (!can)
                    return 0;
                zero_pos = i;
            }
        }
        return tr;
    }
};

// =================================================================

int main()
{
}