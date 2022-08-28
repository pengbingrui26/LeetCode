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

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            // std::cout << i << std::endl;
            int num_5 = 0;
            int k = i;
            while (k % 5 == 0)
            {
                k = k / 5;
                num_5++;
            }
            tot += num_5;
        }
        return tot;
    }
};

int main()
{
}