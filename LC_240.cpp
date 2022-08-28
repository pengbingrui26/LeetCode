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
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        bool tr = 0;
        std::vector<int> rows;
        for (int i = 0; i < M; i++)
        {
            if (matrix[i][0] <= target && matrix[i][N - 1] >= target)
            {
                rows.push_back(i);
            }
        }
        if (rows.size() == 0)
            return 0;
        for (auto row : rows)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[row][j] == target)
                    return 1;
            }
        }
        return 0;
    }
};

int main()
{
}
