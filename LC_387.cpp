
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <set>

class Solution
{
public:
    int firstUniqChar(std::string s)
    {
        std::unordered_map<char, int> HashList;
        for (int i = 0; i < s.size(); i++)
        {
            if (HashList.find(s[i]) == HashList.end())
            {
                HashList[s[i]] = 1;
            }
            else
            {
                HashList[s[i]]++;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (HashList[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

// =============================================================

int main()
{
}