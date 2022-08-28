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
    void connect(std::pair<int, int> xy, std::vector<std::vector<char>> &board, std::vector<std::vector<int>> &visited)
    {
        int x = xy.first;
        int y = xy.second;
        // if (x == 0 || x == M-1 || y == 0 || y== N-1){
        //     return;
        // }
        if (board[x][y] != 'O')
            return;
        visited[xy.first][xy.second] = 1;
        std::vector<std::pair<int, int>> dires = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dire : dires)
        {
            int x_new = x + dire.first;
            int y_new = y + dire.second;
            if (x_new >= 0 && x_new < board.size() && y_new >= 0 && y_new < board[0].size() && visited[x_new][y_new] == 0)
            {
                connect(std::make_pair(x_new, y_new), board, visited);
            }
        }
    }

public:
    void solve(std::vector<std::vector<char>> &board)
    {
        int M = board.size();
        int N = board[0].size();
        std::vector<std::pair<int, int>> zeros;
        for (int i = 0; i < M; i++)
        {
            if (board[i][0] == 'O')
                zeros.push_back(std::make_pair(i, 0));
            if (board[i][N - 1] == 'O')
                zeros.push_back(std::make_pair(i, N - 1));
        }
        for (int j = 0; j < N; j++)
        {
            if (board[0][j] == 'O')
                zeros.push_back(std::make_pair(0, j));
            if (board[M - 1][j] == 'O')
                zeros.push_back(std::make_pair(M - 1, j));
        }
        std::vector<std::vector<int>> visited(M, std::vector<int>(N));
        for (auto xy : zeros)
            connect(xy, board, visited);
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 'O' && visited[i][j] != 1)
                    board[i][j] = 'X';
            }
        }
    }
};

int main()
{
}