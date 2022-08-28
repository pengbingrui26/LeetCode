#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>

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
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        std::cout << "M, N: " << M << ", " << N << std::endl;
        int m = M;
        int n = N;
        std::vector<int> output;
        while (m >= 2 && n >= 2)
        {
            std::cout << "m, n: " << m << ", " << n << std::endl;
            for (int j = (N - n) / 2; j < (N + n) / 2; j++)
                output.push_back(matrix[(M - m) / 2][j]);

            for (int i = (M - m) / 2 + 1; i < (M + m) / 2; i++)
                output.push_back(matrix[i][(N + n) / 2 - 1]);

            for (int j = (N + n) / 2 - 2; j >= (N - n) / 2; j--)
                output.push_back(matrix[(M + m) / 2 - 1][j]);

            for (int i = (M + m) / 2 - 2; i >= (M - m) / 2; i--)
                output.push_back(matrix[i][(N - n) / 2]);

            m -= 2;
            n -= 2;
        }
        return output;
    }
};

// =================================================

void test01()
{
    Solution solution;
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto v = solution.spiralOrder(mat);
    print(v);
}

// =================================================

int main()
{
    test01();
}
