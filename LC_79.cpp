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
private:
    std::vector<std::pair<int, int>> masker(std::vector<std::pair<int, int>> xys, int M, int N)
    {
        std::vector<std::pair<int, int>> output;
        for (auto xy : xys)
        {
            int x = xy.first;
            int y = xy.second;
            if ((x >= 0 && x < M) && (y >= 0 && y < N))
                output.push_back(xy);
        }
        return output;
    }
    std::vector<std::pair<int, int>> all_adjacent(std::pair<int, int> xy, int M, int N)
    {
        std::vector<std::pair<int, int>> output;
        int x = xy.first;
        int y = xy.second;
        output = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        return output;
    }
    std::vector<std::pair<int, int>> adjacent(std::pair<int, int> xy, int M, int N)
    {
        auto all_xys = all_adjacent(xy, M, N);
        auto xys = masker(all_xys, M, N);
        return xys;
    }
    bool connect(std::pair<int, int> start_xy, std::vector<std::vector<char>> &board, std::vector<std::vector<int>> &visited, int M, int N, std::string word)
    {
        // std::cout << word << std::endl;
        if (word.size() == 1)
        {
            int x = start_xy.first;
            int y = start_xy.second;
            return (board[x][y] == word[0] && visited[x][y] == 0);
        }
        else
        {
            int x = start_xy.first;
            int y = start_xy.second;
            if ((board[x][y] != word[0]) || (visited[x][y] == 1))
                return 0;
            visited[x][y] = 1;
            auto xys = adjacent(start_xy, M, N);
            std::string word_new = word.substr(1);
            bool tr = 0;
            for (auto next_xy : xys)
            {
                if (connect(next_xy, board, visited, M, N, word_new))
                {
                    tr = 1;
                    break;
                }
            }
            if (!tr)
                visited[x][y] = 0;
            return tr;
        }
    }

public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        int M = board.size();
        int N = board[0].size();
        std::vector<std::pair<int, int>> starts;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == word[0])
                {
                    // std::cout << i << j << std::endl;
                    starts.push_back(std::make_pair(i, j));
                }
            }
        }
        // std::cout << starts.size() << std::endl;
        bool tr = 0;
        std::vector<std::vector<int>> visited(M, std::vector<int>(N));
        for (auto start : starts)
        {
            if (connect(start, board, visited, M, N, word))
            {
                tr = 1;
                break;
            }
        }
        return tr;
    }
};

/*
class Solution2 {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++){
            for (int j = 0; j < board[0].length; j++) {
                if (search(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return  false;
    }

    boolean search(char[][] board, String word, int i, int j, int k) {
        if (k >= word.length()) return true;
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(k)) return false;
        board[i][j] += 256;
        boolean result = search(board, word, i - 1, j, k + 1) || search(board, word, i + 1, j, k + 1)
                || search(board, word, i, j - 1, k + 1) || search(board, word, i, j + 1, k + 1);
        board[i][j] -= 256;
        return result;
    }
}*/

// ==================================================================

void test01()
{
    Solution1 solution;
    // std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::vector<std::vector<char>> board = {{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
    std::string word = "AAB";
    auto it = solution.exist(board, word);
    std::cout << it << std::endl;
}

// ==================================================================

int main()
{
    test01();
}