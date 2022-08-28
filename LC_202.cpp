#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Solution
{
public:
    bool isHappy(int n)
    {
        bool tr = 0;
        int maxtime = 0;
        while (!tr && maxtime < 50)
        {
            int i = 0;
            int n_new = 0;
            while (n > 0)
            {
                int res = n % 10;
                // int diff = res * std::pow(10, i);
                n_new += res * res;
                n -= res;
                n /= 10;
                i++;
            }
            n = n_new;
            if (n == 1)
            {
                tr = 1;
            }
            maxtime += 1;
        }
        return tr;
    }
};

// =======================================================================

int main()
{
}