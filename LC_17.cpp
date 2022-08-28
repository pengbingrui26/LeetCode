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

class Solution
{
private:
    std::unordered_map<char, std::string> HashList = {{'1', ""}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.size() == 0)
        {
            std::vector<std::string> output;
            return output;
        }
        else if (digits.size() == 1)
        {
            std::vector<std::string> output;
            for (auto cc : HashList[digits[0]])
            {
                std::string tmp(1, cc);
                output.push_back(tmp);
            }
            return output;
        }
        else
        {
            std::string digits_short(digits.begin(), digits.end() - 1);
            auto tmp = letterCombinations(digits_short);
            std::vector<std::string> tmp_new;
            for (auto ss : tmp)
            {
                for (auto cc : HashList[digits.back()])
                {
                    auto ss_new = ss + cc;
                    tmp_new.push_back(ss_new);
                }
            }
            return tmp_new;
        }
    }
};

int main()
{
}