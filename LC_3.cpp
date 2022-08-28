#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>

void print(std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

class Solution1
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> HashList;
        // std::set<char> HashList;
        int front = 0;
        int hind = 0;
        int maxlen = 0;
        while (hind < s.size())
        {
            if (HashList.find(s[hind]) == HashList.end())
            {
                HashList[s[hind]] = hind;
                hind++;
            }
            else
            {
                front = HashList[s[hind]] + 1;
                hind = front;
                HashList.clear();
            }
            if (HashList.size() > maxlen)
            {
                maxlen = HashList.size();
            }
        }
        return maxlen;
    }
};

class Solution2
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
    }
};

int main()
{
}