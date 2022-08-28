#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Solution1
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::unordered_map<int, int> HashList1;
        std::unordered_map<int, int> HashList2;
        if (s.size() != t.size())
        {
            return 0;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (HashList1.find(s[i]) == HashList1.end())
            {
                HashList1[s[i]] = 1;
            }
            else
            {
                HashList1[s[i]]++;
            }
            if (HashList2.find(t[i]) == HashList2.end())
            {
                HashList2[t[i]] = 1;
            }
            else
            {
                HashList2[t[i]]++;
            }
        }
        bool tr = 1;
        for (auto it = HashList1.begin(); it != HashList1.end(); it++)
        {
            if (HashList2.find(it->first) == HashList2.end())
            {
                return 0;
            }
            else if (HashList2[it->first] != it->second)
            {
                return 0;
            }
        }
        return tr;
    }
};

class Solution2
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        bool tr = 1;
        if (s.size() != t.size())
        {
            return 0;
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != t[i])
                {
                    return 0;
                }
            }
            return tr;
        }
    }
};

// ==============================================================================

void test02()
{
}

// ==============================================================================

int main()
{
}
