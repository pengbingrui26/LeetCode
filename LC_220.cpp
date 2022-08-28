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

class Solution1
{
private:
    bool adjacent(std::pair<int, int> a, std::pair<int, int> b)
    {
        int x_diff = a.first - b.first;
        int y_diff = a.second - b.second;
        return ((std::abs(x_diff) == 1 && std::abs(y_diff) == 0) || (std::abs(x_diff) == 0 && std::abs(y_diff) == 1));
    }

public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int M = grid.size();
        int N = grid[0].size();
        std::set<std::set<std::pair<int, int>>> hashlist;

        std::pair<int, int> xy_init;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == '1')
                {
                    std::set<std::pair<int, int>> tmp = {{i, j}};
                    hashlist.insert(tmp);
                    xy_init = std::make_pair(i, j);
                    break;
                }
            }
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] != '1' || std::make_pair(i, j) == xy_init)
                    continue;
                bool exist = 0;
                for (auto it : hashlist)
                {
                    bool tr = 0;
                    for (auto p : it)
                    {
                        if (adjacent(std::make_pair(i, j), p))
                        {
                            tr = 1;
                            break;
                        }
                    }
                    if (tr)
                    {
                        exist = 1;
                        hashlist.erase(it);
                        it.insert(std::make_pair(i, j));
                        hashlist.insert(it);
                    }
                }
                if (!exist)
                    hashlist.insert({{std::make_pair(i, j)}});
            }
        }
        return hashlist.size();
    }
};

// ==============================================

void test01()
{
    Solution1 solution;
    std::vector<std::vector<char>> grid;
    grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    auto it = solution.numIslands(grid);
    std::cout << it << std::endl;
}

// ==============================================

int main()
{
    test01();
}
