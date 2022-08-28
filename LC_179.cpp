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

class Solution1
{
private:
    static bool cmp(std::string str1, std::string str2)
    {
        int N = std::min(str1.size(), str2.size());
        for (int i = 0; i < N; i++)
        {
            int head1 = str1[i] - '0';
            int head2 = str2[i] - '0';
            if (head1 > head2)
                return 1;
        }
        return 0;
    }

public:
    std::string largestNumber(std::vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return std::to_string(nums[0]);
        }
        std::unordered_map<int, std::vector<int>> hashlist;
        for (int i = 0; i < nums.size(); i++)
        {
            std::string str = std::to_string(nums[i]);
            int head = str[0] - '0';
            if (hashlist.find(head) == hashlist.end())
                hashlist[head] = {i};
            else
                hashlist[head].push_back(i);
        }
        int maxkey = hashlist.begin()->first;
        for (auto it : hashlist)
        {
            if (it.first > maxkey)
                maxkey = it.first;
        }
        std::vector<int> max_idx = hashlist[maxkey];

        std::vector<std::string> sss;

        for (auto idx : max_idx)
        {
            int first_num = nums[idx];
            std::vector<int> tmp = nums;
            tmp.erase(tmp.begin() + idx);
            std::string cur = std::to_string(first_num) + largestNumber(tmp);
            sss.push_back(cur);
        }

        if (sss.size() == 1)
            return sss[0];

        for (int k = sss.size() - 1; k >= 0; k--)
        {
            for (int r = 0; r < k; r++)
            {
                if (cmp(sss[r], sss[r + 1]))
                {
                    std::string tmp = sss[r];
                    sss[r] = sss[r + 1];
                    sss[r + 1] = tmp;
                }
            }
        }

        std::string output = sss[sss.size() - 1];
        return output;
    }
};

class Solution2
{
public:
    /*static bool cmp(string& a, string& b){
        return a + b > b + a;
    }*/
    std::string largestNumber(std::vector<int> &nums)
    {
        std::vector<std::string> cpy;
        for (auto x : nums)
        {
            cpy.push_back(std::to_string(x));
        }
        // sort(cpy.begin(), cpy.end(), cmp);
        std::sort(cpy.begin(), cpy.end(), [](const std::string &a, const std::string &b)
                  { return a + b > b + a; });
        std::string ans;
        bool start = 1;
        for (auto x : cpy)
        {
            if (start)
            {
                if (x == "0")
                {
                    continue;
                }
                else
                {
                    start = 0;
                }
            }
            ans += x;
        }
        return ans.size() ? ans : "0";
    }
};

// ==============================================================

void test02()
{
    Solution2 solution;
    std::vector<int> nums = {3, 30, 34, 5, 9};
    auto it = solution.largestNumber(nums);
    std::cout << it << std::endl;
}

// ==============================================================

int main()
{
    test02();
}