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

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        std::set<std::pair<int, int>> hashlist;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (hashlist.find(std::make_pair(i, j)) == hashlist.end() && matrix[i][j] == 0)
                {
                    for (int k = 0; k < N; k++)
                    {
                        if (matrix[i][k] != 0)
                        {
                            hashlist.insert(std::make_pair(i, k));
                            matrix[i][k] = 0;
                        }
                    }
                    for (int r = 0; r < M; r++)
                    {
                        if (matrix[r][j] != 0)
                        {
                            hashlist.insert(std::make_pair(r, j));
                            matrix[r][j] = 0;
                        }
                    }
                }
            }
        }
    }
};

int main()
{
}