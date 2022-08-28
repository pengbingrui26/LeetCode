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
    std::vector<std::pair<int, int>> adjacent(std::pair<int, int> xy, std::vector<std::vector<int>> &board)
    {
        int M = board.size();
        int N = board[0].size();
        int x = xy.first;
        int y = xy.second;
        std::vector<std::pair<int, int>> direcs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        std::vector<std::pair<int, int>> output;
        for (auto direc : direcs)
        {
            int x_new = x + direc.first;
            int y_new = y + direc.second;
            if (x_new >= 0 && x_new < M && y_new >= 0 && y_new < N)
            {
                output.push_back(std::make_pair(x_new, y_new));
            }
        }
        return output;
    }

public:
    void gameOfLife(std::vector<std::vector<int>> &board)
    {
        int M = board.size();
        int N = board[0].size();
        std::vector<std::vector<int>> state(M, std::vector<int>(N));
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // std::cout << "i, j: " << i << ", " << j << std::endl;
                auto xy_adjacent = adjacent(std::make_pair(i, j), board);
                // std::cout << "size adjacent: " << xy_adjacent.size() << std::endl;
                int num_1 = 0;
                for (auto xy : xy_adjacent)
                {
                    int x = xy.first;
                    int y = xy.second;
                    if (board[x][y] == 1)
                        num_1++;
                }
                // std::cout << "num_1: " << num_1 << std::endl;
                if (board[i][j] == 1)
                {
                    if (num_1 < 2 || num_1 > 3)
                    {
                        // std::cout << "change" << std::endl;
                        state[i][j] = 1;
                    }
                }
                else
                {
                    if (num_1 == 3)
                    {
                        // std::cout << "change" << std::endl;
                        state[i][j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (state[i][j] == 1)
                {
                    if (board[i][j] == 1)
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                }
            }
        }
    }
};

int main()
{
}