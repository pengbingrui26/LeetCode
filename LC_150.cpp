#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
#include <tuple>
#include <map>

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
private:
    std::set<std::string> operators = {"+", "-", "*", "/"};
    int DoMath(int a, int b, std::string oper)
    {
        if (oper == "+")
            return a + b;
        else if (oper == "-")
            return a - b;
        else if (oper == "*")
            return a * b;
        else if (oper == "/")
            return a / b;
        return a;
    }

public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> ss;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (operators.find(tokens[i]) == operators.end())
            {
                ss.push(std::stoi(tokens[i]));
            }
            else
            {
                int hind = ss.top();
                ss.pop();
                int front = ss.top();
                ss.pop();
                int x = DoMath(front, hind, tokens[i]);
                ss.push(x);
            }
        }
        return ss.top();
    }
};

int main()
{
}