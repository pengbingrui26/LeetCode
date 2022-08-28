#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>

void print(std::vector<std::string> &v)
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
    std::vector<std::string> generateParenthesis(int n)
    {
        if (n == 0)
        {
            std::vector<std::string> output;
            output = {""};
            return output;
        }
        else if (n == 1)
        {
            std::vector<std::string> output;
            output = {"()"};
            return output;
        }
        else
        {
            std::vector<std::string> output;
            for (int i = 1; i <= n; i++)
            {
                int front = i;
                int hind = n - i;
                auto output_a = generateParenthesis(front - 1);
                auto output_b = generateParenthesis(hind);
                // std::cout << "output_a" << std::endl;
                // std::cout << "output_b" << std::endl;
                // print(output_a);
                // print(output_b);
                for (auto aa : output_a)
                {
                    for (auto bb : output_b)
                    {
                        auto aa_new = "(" + aa + ")";
                        auto cc = aa_new + bb;
                        // std::cout << "aa: " << aa << std::endl;
                        // std::cout << "bb: " << bb << std::endl;
                        // std::cout << "cc: " << cc << std::endl;
                        output.push_back(cc);
                    }
                }
            }
            // auto output_last = generateParenthesis(hind);
            return output;
        }
    }
};

// ===========================================================

void test01()
{
    Solution solution;
    auto it = solution.generateParenthesis(3);
    print(it);
}

// ===========================================================

int main()
{
    test01();
}
