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
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> hashlist;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashlist.find(nums[i]) == hashlist.end())
                hashlist[nums[i]] = 1;
            else
                hashlist[nums[i]] += 1;
        }
        std::vector<std::pair<int, int>> vec;
        for (auto it : hashlist)
        {
            vec.push_back(it);
            std::cout << it.first << ", " << it.second << std::endl;
        }
        std::sort(vec.begin(), vec.end(), [](std::pair<int, int> a, std::pair<int, int> b)
                  { return a.second < b.second; });
        std::vector<int> output;
        for (int i = 1; i <= k; i++)
            output.push_back(vec[vec.size() - i].first);
        return output;
    }
};

int main()
{
}