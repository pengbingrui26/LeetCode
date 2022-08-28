#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>

void print(std::vector<int> &v)
{
    for (auto it : v)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        /*for (int i = 0; i < intervals.size(); i ++){
            for (int j = i+1; j < intervals.size(); j++){
                if (intervals[i][0] > intervals[j][0]){
                    auto tmp = intervals[i];
                    intervals[i] = intervals[j];
                    intervals[j] = tmp;
                }
            }
        }*/
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b)
                  { return a[0] < b[0]; });
        // std::cout << intervals_ordered.size() << std::endl;
        std::vector<std::vector<int>> output;
        output.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            auto tmp = intervals[i];
            auto tail = output.back();
            if (tail[1] >= tmp[0])
            {
                std::vector<int> inter_new = {tail[0], std::max(tail[1], tmp[1])};
                output.pop_back();
                output.push_back(inter_new);
            }
            else
            {
                output.push_back(tmp);
            }
        }
        return output;
    }
};

// ==============================================================

int main()
{
}
