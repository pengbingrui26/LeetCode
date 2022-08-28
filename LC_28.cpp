#include <iostream>
#include <string>

class Solution1
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        int i = 0;
        bool find = 0;
        int pos = -1;
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        while (i < (haystack.size() - needle.size() + 1))
        {
            if (haystack[i] == needle[0])
            {
                bool match = 1;
                for (int j = 0; j < needle.size(); j++)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        match = 0;
                        break;
                    }
                }
                if (match)
                {
                    find = 1;
                    pos = i;
                    break;
                }
            }
            i++;
        }
        return pos;
    }
};

int main()
{
}