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

void print(std::vector<int> &v)
{
    for (auto it : v)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

class Solution1
{
public:
    int uniquePaths(int m, int n)
    {
        m--;
        n--;
        long long re = 1;
        long long k = m + n;
        for (int x = m + 1; x <= m + n; x++)
            re = re * x;
        for (int y = 1; y <= n; y++)
            re = re / y;
        return re;
    }
};

class Solution2
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> hashlist(m, std::vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // std::cout << "i, j: " << i << "," << j << std::endl;
                if (i == 0 && j == 0)
                    hashlist[i][j] = 1;
                else if (i == 0 || j == 0)
                    hashlist[i][j] = 1;
                else
                    hashlist[i][j] = hashlist[i - 1][j] + hashlist[i][j - 1];
            }
        }
        return hashlist[m - 1][n - 1];
    }
};

// =================================================================

void test01()
{
    Solution2 solution;
    auto it = solution.uniquePaths(3, 2);
    std::cout << it << std::endl;
}

int main()
{
    test01();
}