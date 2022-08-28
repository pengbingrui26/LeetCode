#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>

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
    std::string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        else
        {
            auto last = countAndSay(n - 1);
            std::string tmp;
            int i = 0;
            while (i < last.size())
            {
                int j = i;
                int num = 0;
                while (j < last.size())
                {
                    if (last[j] == last[i])
                        num++;
                    else
                        break;
                    j++;
                }
                tmp += std::to_string(num);
                tmp.push_back(last[i]);
                i = j;
            }
            return tmp;
        }
    }
};

// =======================================================

void test01()
{
    Solution solution;
    int n = 3;
    auto it = solution.countAndSay(4);
    std::cout << it << std::endl;
}

// ========================================================

int main()
{
    test01();
}