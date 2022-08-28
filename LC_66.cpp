#include <iostream>
#include <vector>
#include <cmath>

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
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int sum = 0;
        for (int i = (digits.size() - 1); i >= 0; i--)
        {
            sum += digits[digits.size() - 1 - i] * std::pow(10, i);
        }
        sum++;
        int sum_new = sum;
        int j = 1;
        std::vector<int> output;
        while (sum > 0)
        {
            int dividor = std::pow(10, j);
            int re = sum % dividor;
            output.insert(output.begin(), re);
            sum = (sum - re) / dividor;
        }
        return output;
    }
};

// ===============================================================

void test01()
{
    Solution1 solution;
    std::vector<int> digits = {4, 3, 2, 1};
    auto v = solution.plusOne(digits);
    print(v);
}

// ===============================================================

int main()
{
    test01();
}
