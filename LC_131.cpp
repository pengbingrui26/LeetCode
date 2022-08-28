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

class Solution
{
private:
    bool symmetric(std::string str)
    {
        if (str.size() == 0)
            return 0;
        bool tr = 1;
        int i = 0;
        int j = str.size() - 1;
        while (i <= j)
        {
            if (str[i] != str[j])
                return 0;
            i++;
            j--;
        }
        return tr;
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        if (s.size() == 1)
            return {{s}};
        else
        {
            std::vector<std::vector<std::string>> output;
            if (symmetric(s))
                output.push_back({s});
            for (int i = 1; i < s.size(); i++)
            {
                std::string s1 = s.substr(0, i);
                std::string s2 = s.substr(i);
                if (symmetric(s1))
                {
                    auto output_s2 = partition(s2);
                    for (auto s2 : output_s2)
                    {
                        std::vector<std::string> tmp = s2;
                        tmp.insert(tmp.begin(), s1);
                        output.push_back(tmp);
                    }
                }
            }
            return output;
        }
    }
};

int main()
{
}
