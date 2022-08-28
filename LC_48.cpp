#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>

void print(std::vector<int> &v)
{
    for (auto it : v)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

void print2(std::vector<std::vector<int>> &vv)
{
    for (auto v : vv)
    {
        print(v);
    }
    std::cout << std::endl;
}

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int N = matrix.size();
        for (int n = N; n >= 2; n -= 2)
        {
            std::cout << "n = " << n << std::endl;
            std::unordered_map<int, std::pair<int, int>> hashlist;
            std::vector<int> vv;
            int i = (N - n) / 2;
            int j = (N - n) / 2;
            int num = 0;
            while (j < (N + n) / 2)
            {
                std::cout << "i, j: " << i << ", " << j << std::endl;
                hashlist[num] = std::make_pair(i, j);
                vv.push_back(matrix[i][j]);
                j++;
                num++;
            }
            j--;
            i++;
            while (i < (N + n) / 2)
            {
                std::cout << "i, j: " << i << ", " << j << std::endl;
                hashlist[num] = std::make_pair(i, j);
                vv.push_back(matrix[i][j]);
                i++;
                num++;
            }
            i--;
            j--;
            while (j >= (N - n) / 2)
            {
                std::cout << "i, j: " << i << ", " << j << std::endl;
                hashlist[num] = std::make_pair(i, j);
                vv.push_back(matrix[i][j]);
                j--;
                num++;
            }
            j++;
            i--;
            while (i > (N - n) / 2)
            {
                std::cout << "i, j: " << i << ", " << j << std::endl;
                hashlist[num] = std::make_pair(i, j);
                vv.push_back(matrix[i][j]);
                i--;
                num++;
            }
            std::cout << "vv: ";
            print(vv);
            for (int k = 0; k < vv.size(); k++)
            {
                int ii = hashlist[(k + n - 1) % vv.size()].first;
                int jj = hashlist[(k + n - 1) % vv.size()].second;
                matrix[ii][jj] = vv[k];
            }
        }
    }
};

// ===========================================================

void test01()
{
    Solution solution;
    // std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> mat = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    print2(mat);
    solution.rotate(mat);
    print2(mat);
}

// ===========================================================

int main()
{
    test01();
}
