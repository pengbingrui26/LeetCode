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
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        int N = gas.size();
        std::vector<int> starts;
        for (int i = 0; i < N; i++)
        {
            if (gas[i] >= cost[i])
                starts.push_back(i);
        }
        bool tr = 0;
        int idx;
        for (int k : starts)
        {
            bool ok = 1;
            int diff = 0;
            for (int j = 0; j < N; j++)
            {
                int jj = (j + k) % N;
                diff += (gas[jj] - cost[jj]);
                if (diff < 0)
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                idx = k;
                tr = 1;
                break;
            }
        }
        if (!tr)
            return -1;
        else
            return idx;
    }
};

class Solution2
{
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        int N = gas.size();
        int thisval = 0;
        int maxval = gas[0] - cost[0];
        for (int i = 0; i < N; i++)
        {
            int j = 0;
            while (j < N)
            {
                thisval += (gas[(i + j) % N] - cost[(i + j) % N]);
                if (thisval < 0)
                {
                    thisval = 0;
                    break;
                }
                if (thisval > maxval)
                    maxval = thisval;
                j++;
            }
            if (j == N)
            {
                return i;
            }
        }
        return -1;
    }
};

// =======================================================

void test01()
{
}

// =======================================================

int main()
{
}
