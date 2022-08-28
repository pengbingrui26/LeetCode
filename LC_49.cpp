#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> hashlist;
        for (auto str : strs)
        {
            std::string tmp = str;
            std::sort(tmp.begin(), tmp.end());
            if (hashlist.find(tmp) == hashlist.end())
                hashlist[tmp] = {str};
            else
                hashlist[tmp].push_back(str);
        }
        std::vector<std::vector<std::string>> output;
        for (auto it = hashlist.begin(); it != hashlist.end(); it++)
            output.push_back(it->second);
        return output;
    }
};

int main()
{
}
