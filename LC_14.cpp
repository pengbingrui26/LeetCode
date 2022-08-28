#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        bool stop = 0;
        std::string common_str;
        int Nstr = strs.size();
        int i = 0;
        if (Nstr == 0)
        {
            stop = 1;
        }
        if (Nstr == 1)
        {
            common_str = strs[0];
            stop = 1;
        }
        while (!stop)
        {
            char tmp = strs[0][i];
            bool tr = 1;
            for (int k = 1; k < Nstr; k++)
            {
                if (strs[k][i] != tmp || i >= strs[k].size())
                {
                    tr = 0;
                    break;
                }
            }
            if (tr)
            {
                common_str.push_back(tmp);
            }
            else
            {
                stop = 1;
            }
            i += 1;
        }
        return common_str;
    }
};

// ============================================================

void test01()
{
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    Solution solution;
    auto output = solution.longestCommonPrefix(strs);
    std::cout << output << std::endl;
}

// ============================================================

int main()
{
    test01();
}
