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
    int getSum(int a, int b)
    {
        if (b == 0)
            return a;
        int i = 0;
        while (i < std::abs(b))
        {
            if (b > 0)
                a++;
            else
                a--;
            i++;
        }
        return a;
    }
};

int main()
{
}