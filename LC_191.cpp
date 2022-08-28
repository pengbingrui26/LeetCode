#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Solution
{
public:
    int hammingWeight(int n)
    {
        int i = 1;
        int num = 0;
        n = int(n);
        while (n > 0)
        {
            int dividor = std::pow(2, i);
            auto re = n % dividor;
            if (re / std::pow(2, i - 1) == 1)
            {
                num++;
            }
            n -= re;
            i++;
        }
        return num;
    }
};