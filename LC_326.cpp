#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <set>

class Solution1
{
public:
    bool isPowerOfThree(int n)
    {
        bool tr = 0;
        // int i = 0;
        int thisnum = 1;
        while (!tr)
        {
            if (thisnum <= n && thisnum * 3 >= n)
            {
                if (thisnum == n || thisnum * 3 == n)
                {
                    tr = 1;
                }
                else
                {
                    tr = 0;
                }
                break;
            }
            thisnum *= 3;
        }
        return tr;
    }
};

// ===========================================================

void test01()
{
    Solution1 solution;
    auto tr = solution.isPowerOfThree(1162261468);
    std::cout << tr << std::endl;
}

// ===========================================================

int main()
{
    test01();
}
