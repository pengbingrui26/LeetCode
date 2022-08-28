#include <iostream>
#include <vector>
#include <cmath>

// Newtown

class Solution
{
public:
    double mySqrt(int x)
    {
        double x0 = 10.;
        double y0 = x0 * x0 - x;
        while (std::abs(y0) > 0.1)
        {
            x0 = (x0 * x0 + x) / (2 * x0);
            y0 = x0 * x0 - x;
        }
        return std::floor(x0);
    }
};

// ==============================================================

void test01()
{
    Solution solution;
    auto p = solution.mySqrt(16.);
    std::cout << p << std::endl;
}

// ===============================================================

int main()
{
    test01();
}