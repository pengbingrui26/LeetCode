#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::unordered_map<char, int> dic = {{'(', 1}, {'[', 3}, {'{', 5}, {')', 2}, {']', 4}, {'}', 6}};
        std::vector<char> stack;
        bool tr = 1;
        for (int k = 0; k < s.size(); k++)
        {
            if (dic[s[k]] % 2 == 1)
            {
                stack.push_back(s[k]);
            }
            else
            {
                if (stack.size() == 0)
                {
                    tr = 0;
                    break;
                }
                else if (dic[s[k]] == (dic[stack.back()] + 1))
                {
                    stack.pop_back();
                }
                else
                {
                    tr = 0;
                    break;
                }
            }
        }
        if (stack.size() != 0)
        {
            tr = 0;
        }
        return tr;
    }
};

// ====================================================

void test01()
{
}

// ======================================================

int main()
{
}
