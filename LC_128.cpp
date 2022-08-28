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
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        int i = 0;
        int j = i;
        int maxlen = 0;
        while (i < nums.size())
        {
            while (j < nums.size())
            {
                if (nums[j] - nums[i] != (j - i))
                    break;
                j++;
            }
            if (j - i > maxlen)
                maxlen = j - i;
            i = j;
        }
        return maxlen;
    }
};

int main()
{
}