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
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        if (s.size() == 0)
            return 1;
        else
        {
            std::set<std::string> hashlist;
            std::vector<int> words_first;
            for (auto word : wordDict)
                hashlist.insert(word);
            int i = 1;
            while (i <= s.size())
            {
                auto tmp = s.substr(0, i);
                // for (auto word:wordDict){
                //     if (tmp == word)
                //         words_first.push_back(i);
                if (hashlist.find(tmp) != hashlist.end())
                    words_first.push_back(i);
                i++;
            }
            if (words_first.size() == 0)
                return 0;
            else
            {
                bool tr = 0;
                for (auto k : words_first)
                {
                    std::string s_next(s.begin() + k, s.end());
                    if (wordBreak(s_next, wordDict))
                    {
                        tr = 1;
                        break;
                    }
                }
                return tr;
            }
        }
    }
};

int main()
{
}
