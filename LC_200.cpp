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
private:
    void connect(std::pair<int, int> xy, std::vector<std::vector<char>> &grid, std::vector<std::vector<int>> &visited)
    {
        int M = grid.size();
        int N = grid[0].size();
        int x = xy.first;
        int y = xy.second;

        if (grid[x][y] != '1')
            return;
        if (visited[x][y] == 1)
            return;

        visited[x][y] = 1;
        std::vector<std::pair<int, int>> direcs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto direc : direcs)
        {
            int x_new = x + direc.first;
            int y_new = y + direc.second;
            // std::cout << x_new << ", " << y_new << std::endl;
            if (x_new >= 0 && x_new < M && y_new >= 0 && y_new < N)
            {
                connect(std::make_pair(x_new, y_new), grid, visited);
            }
        }
    }

public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int M = grid.size();
        int N = grid[0].size();
        std::vector<std::vector<int>> visited(M, std::vector<int>(N));

        int num = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] != '1')
                    continue;
                if (visited[i][j] == 1)
                    continue;
                num++;
                connect(std::make_pair(i, j), grid, visited);
            }
        }
        return num;
    }
};

int main()
{
}