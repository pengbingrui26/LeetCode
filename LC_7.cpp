#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>

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
    int reverse(int x)
    {
        bool sign = (x >= 0) ? 1 : 0;
        int output = 0;
        if (!sign)
        {
            x = -x;
        }
        std::vector<int> v;
        while (x > 0)
        {
            int re = x % 10;
            v.insert(v.begin(), re);
            x -= re;
            x = x / 10;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (std::pow(10, i) > std::pow(2, 31))
            {
                return 0;
            }
            output += v[i] * std::pow(10, i);
        }
        if (!sign)
        {
            output = -output;
        }
        return output;
    }
};

class Solution2
{
public:
    int reverse(int x)
    {
        bool sign = (x >= 0) ? 1 : 0;
        if (!sign)
        {
            x = -x;
        }
        std::string s = std::to_string(x);
        std::stack<char> v;
        for (int i = 0; i < s.size(); i++)
        {
            v.push(s[i]);
        }
        std::string s_reverse;
        while (!v.empty())
        {
            auto tmp = v.top();
            s_reverse.push_back(tmp);
            v.pop();
        }
        int output = std::stoi(s_reverse);
        if (!sign)
        {
            output = -output;
        }
        return output;
    }
};

// ==============================================================

void test02()
{
    Solution2 solution;
    auto it = solution.reverse(1534236469);
    std::cout << it << std::endl;
}

// ==============================================================

int main()
{
    test02();
}