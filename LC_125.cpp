#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        // std::cout << s << std::endl;
        std::string ss;
        // std::cout << s << std::endl;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (std::isalpha(*it) || std::isdigit(*it))
            {
                ss.push_back(*it);
            }
        }
        bool tr = 1;
        for (int k = (ss.size() / 2 - 1); k >= 0; k--)
        {
            if (ss[k] != ss[ss.size() - 1 - k])
            {
                tr = 0;
                break;
            }
        }
        return tr;
    }
};

// ================================================

void test01()
{
    std::string str = "0P";
    Solution solution;
    auto tt = solution.isPalindrome(str);
    std::cout << tt << std::endl;
}

// ==========================================================

int main()
{
    test01();
}