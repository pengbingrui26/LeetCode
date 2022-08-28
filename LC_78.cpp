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
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> output;
        std::map<int, std::vector<std::vector<int>>> hashlist;
        hashlist[0] = {{}};
        // hashlist[1] = {};
        for (int n = 0; n < nums.size(); n++)
            hashlist[1].push_back({nums[n]});
        for (int i = 2; i <= nums.size(); i++)
        {
            // hashlist[i] = {};
            for (auto arr : hashlist[i - 1])
            {
                for (int k = 0; k < nums.size(); k++)
                {
                    if (std::find(arr.begin(), arr.end(), nums[k]) == arr.end())
                    {
                        std::vector<int> arr_new = arr;
                        arr_new.push_back(nums[k]);
                        std::sort(arr_new.begin(), arr_new.end());
                        if (std::find(hashlist[i].begin(), hashlist[i].end(), arr_new) == hashlist[i].end())
                            hashlist[i].push_back(arr_new);
                    }
                }
            }
        }
        for (auto vv : hashlist)
        {
            std::cout << vv.first << "," << vv.second.size() << std::endl;
            for (auto v : vv.second)
                output.push_back(v);
        }
        return output;
    }
};

int main()
{
}