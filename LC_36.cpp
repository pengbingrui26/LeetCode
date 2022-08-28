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

class Solution1
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        bool tr = 1;
        for (int i = 0; i < 9; i++)
        {
            std::set<char> hashlist;
            for (int j = 0; j < 9; j++)
            {
                if (hashlist.find(board[i][j]) == hashlist.end())
                    hashlist.insert(board[i][j]);
                else
                    return 0;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            std::set<char> hashlist;
            for (int j = 0; j < 9; j++)
            {
                if (hashlist.find(board[j][i]) == hashlist.end())
                    hashlist.insert(board[j][i]);
                else
                    return 0;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::set<char> hashlist;
                for (int ii = 0; ii < 3; ii++)
                {
                    for (int jj = 0; jj < 3; jj++)
                    {
                        if (hashlist.find(board[i * 3 + ii][j * 3 + jj]) == hashlist.end())
                            hashlist.insert(board[i * 3 + ii][j * 3 + jj]);
                        else
                            return 0;
                    }
                }
            }
        }
        return tr;
    }
};

class Solution2
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        bool tr = 1;
        std::vector<std::set<char>> row(9);
        std::vector<std::set<char>> col(9);
        std::vector<std::vector<std::set<char>>> lattice(3, std::vector<std::set<char>>(3));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (row[i].find(board[i][j]) == row[i].end())
                    row[i].insert(board[i][j]);
                else
                    return 0;
                if (col[j].find(board[i][j]) == col[j].end())
                    col[j].insert(board[i][j]);
                else
                    return 0;
                if (lattice[i / 3][j / 3].find(board[i][j]) == lattice[i / 3][j / 3].end())
                    lattice[i / 3][j / 3].insert(board[i][j]);
                else
                    return 0;
            }
        }
        return tr;
    }
};

int main()
{
}