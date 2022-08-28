#include <iostream>
#include <string>
#include <cmath>

class Solution1
{
public:
    std::string reformat(std::string s)
    {
        std::string digits = "";
        std::string alphas = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (std::isdigit(s[i]))
            {
                digits.push_back(s[i]);
            }
            else
            {
                alphas.push_back(s[i]);
            }
        }
        int len_diff = digits.size() - alphas.size();
        len_diff = std::abs(len_diff);
        if (len_diff > 1)
        {
            return "";
        }
        else
        {
            std::string output = "";
            if (digits.size() > alphas.size())
            {
                for (int k = 0; k < alphas.size(); k++)
                {
                    output.push_back(digits[k]);
                    output.push_back(alphas[k]);
                }
                output.push_back(digits[digits.size() - 1]);
            }
            else if (digits.size() < alphas.size())
            {
                for (int k = 0; k < digits.size(); k++)
                {
                    output.push_back(alphas[k]);
                    output.push_back(digits[k]);
                }
                output.push_back(alphas[alphas.size() - 1]);
            }
            else
            {
                for (int k = 0; k < alphas.size(); k++)
                {
                    output.push_back(digits[k]);
                    output.push_back(alphas[k]);
                }
            }
            return output;
        }
    }
};

class Solution2
{
public:
    std::string reformat(std::string s)
    {
        std::string output(s.size(), '0');
        if (s.size() % 2 != 0)
        {
            output.append(1, '0');
        }
        int num_digit = 0;
        int num_alpha = 0;
        int i = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                output[num_digit * 2] = s[i];
                num_digit += 1;
            }
            else
            {
                output[num_alpha * 2 + 1] = s[i];
                num_alpha += 1;
            }
        }
        int num_diff = num_digit - num_alpha;
        num_diff = std::abs(num_diff);
        if (num_diff > 1)
        {
            return "";
        }
        else if (s.size() % 2 == 0)
        {
            return output;
        }
        else if (num_digit * 2 > s.size())
        {
            output.erase(output.size() - 1, 1);
            return output;
        }
        else
        {
            output.insert(0, 1, output[output.size() - 1]);
            output.erase(output.size() - 2, 2);
            return output;
        }
    }
};

// test =====================================================

void test01()
{
    Solution1 solution;
    std::string ss = "abc123";
    auto ss_new = solution.reformat(ss);
    std::cout << ss_new << std::endl;
}

void test02()
{
    Solution2 solution;
    std::string ss = "abc123";
    auto ss_new = solution.reformat(ss);
    std::cout << ss_new << std::endl;
}
// ==========================================================

int main()
{
    // test01();
    test02();
}
