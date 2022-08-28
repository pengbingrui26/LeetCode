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
    int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        std::vector<int> v;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
                v.push_back(matrix[i][j]);
        }
        std::sort(v.begin(), v.end());
        return v[k - 1];
    }
};

int main()
{
}