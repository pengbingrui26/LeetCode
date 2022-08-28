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
    int numSquares(int n)
    {
        if (n == 1)
            return 1;
        std::unordered_map<int, int> hashlist;
        hashlist[0] = 0;
        hashlist[1] = 1;
        for (int k = 2; k <= n; k++)
        {
            int i = 0;
            while (i <= 100)
            {
                if (i * i > k)
                    break;
                i++;
            }
            i--;
            std::vector<int> nums;
            for (int j = 1; j <= i; j++)
            {
                nums.push_back(hashlist[k - j * j] + 1);
            }
            int a = *std::min_element(nums.begin(), nums.end());
            // std::cout << "k, i: " << k << ", " << i << std::endl;
            hashlist[k] = a;
        }
        // for (auto it:hashlist){
        //     std::cout << it.first << ": " << it.second << std::endl;
        // }
        return hashlist[n];
    }
};

int main()
{
}