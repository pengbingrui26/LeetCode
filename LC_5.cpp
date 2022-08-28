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
    std::string longestPalindrome(std::string s)
    {
        std::string output;
        if (s.size() == 1)
        {
            return s;
        }
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = s.size() - 1; j >= i; j--)
            {
                bool tr = 1;
                std::string tmp(j - i + 1, '1');
                int ii = i;
                int jj = j;
                while (ii <= jj)
                {
                    if (s[ii] != s[jj])
                    {
                        tr = 0;
                        break;
                    }
                    if (ii != jj)
                    {
                        tmp[ii - i] = s[ii];
                        tmp[jj - i] = s[jj];
                    }
                    else
                    {
                        tmp[ii - i] = s[ii];
                    }
                    ii++;
                    jj--;
                }
                if (tr)
                {
                    if (tmp.size() > output.size())
                    {
                        output = tmp;
                    }
                }
            }
        }
        return output;
    }
};

class Solution2
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string output;
        if (s.size() == 1)
        {
            return s;
        }
        if (s.size() == 2)
        {
            if (s[0] == s[1])
                return s;
            else
            {
                return {s[0]};
            }
        }
        for (int i = 1; i < s.size() - 1; i++)
        {
            int j = i - 1;
            int k = i + 1;
            std::string tmp;
            tmp.push_back(s[i]);
            while (j >= 0 && k <= s.size() - 1)
            {
                if (s[j] != s[k])
                {
                    break;
                }
                tmp.insert(tmp.begin(), s[j]);
                tmp.insert(tmp.end(), s[k]);
                j--;
                k++;
            }
            if (tmp.size() > output.size())
            {
                output = tmp;
            }
        }
        for (int i = 0; i < s.size() - 1; i++)
        {
            int j = i;
            int k = i + 1;
            std::string tmp;
            while (j >= 0 && k <= s.size() - 1)
            {
                if (s[j] != s[k])
                {
                    break;
                }
                tmp.insert(tmp.begin(), s[j]);
                tmp.insert(tmp.end(), s[k]);
                j--;
                k++;
            }
            if (tmp.size() > output.size())
            {
                output = tmp;
            }
        }
        return output;
    }
};

// ========================================================================================

int main()
{
}