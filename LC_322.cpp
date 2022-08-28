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
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::unordered_map<int, int> hashlist;
        hashlist[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            int num = amount;
            bool exist = 0;
            for (auto x : coins)
            {
                if (i - x < 0)
                    continue;
                int remain = i - x;
                if (hashlist.find(remain) == hashlist.end())
                    continue;
                else
                {
                    int this_num = hashlist[remain] + 1;
                    exist = 1;
                    if (this_num < num)
                        num = this_num;
                }
            }
            if (i == amount && !exist)
                return -1;
            if (exist)
                hashlist[i] = num;
        }
        // for (auto it:hashlist){
        //     std::cout << it.first << ", " << it.second << std::endl;
        // }
        return hashlist[amount];
    }
};

int main()
{
}