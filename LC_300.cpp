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

class Solution
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        int N = nums.size();
        int maxlen = 0;
        std::set<std::vector<int>> subarrs;
        subarrs.insert({nums[N - 1]});

        for (int i = N - 1; i >= 0; i--)
        {
            bool exist1 = 0;
            bool exist2 = 0;
            // std::vector<int> cur = {nums[i]};
            for (auto subarr : subarrs)
            {
                if (nums[i] < subarr[0])
                {
                    exist1 = 1;
                    std::vector<int> tmp = subarr;
                    tmp.insert(tmp.begin(), nums[i]);
                    subarrs.insert(tmp);
                }
                if (nums[i] == subarr[0])
                    exist2 = 1;
            }
            if (!exist1 && !exist2)
                subarrs.insert({nums[i]});
        }

        for (auto it : subarrs)
        {
            if (it.size() > maxlen)
            {
                maxlen = it.size();
            }
        }
        return maxlen;
    }
};

int main()
{
}