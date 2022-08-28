#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <set>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        if (s.size() > 1)
        {
            for (int i = s.size() / 2 - 1; i >= 0; i--)
            {
                int tmp = s[i];
                s[i] = s[s.size() - i - 1];
                s[s.size() - i - 1] = tmp;
            }
        }
    }
};

// ===========================================================

void test01()
{
    Solution solution;
}

// ===========================================================

int main()
{
    test01();
}
