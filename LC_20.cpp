#include <iostream>
#include <string>

class Solution
{
public:
    bool isValid(std::string s)
    {
        bool tr = 1;

        int left_small = 0;
        int right_small = 0;

        int left_middle = 0;
        int right_middle = 0;

        int left_big = 0;
        int right_big = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                left_small += 1;
                if (i == s.size() - 1)
                {
                    tr = 0;
                    break;
                }
                else if (s[i + 1] == ']' || s[i + 1] == '}')
                {
                    tr = 0;
                    break;
                }
            }
            else if (s[i] == ')')
            {
                right_small += 1;
                if (i == 0)
                {
                    tr = 0;
                    break;
                }
                else if (s[i - 1] == '[' || s[i - 1] == '{')
                {
                    tr = 0;
                    break;
                }
            }
            else if (s[i] == '[')
            {
                left_middle += 1;
                if (i == s.size() - 1)
                {
                    tr = 0;
                    break;
                }
                else if (s[i + 1] == ')' || s[i + 1] == '}')
                {
                    tr = 0;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                right_middle += 1;
                if (i == 0)
                {
                    tr = 0;
                    break;
                }
                else if (s[i - 1] == '(' || s[i - 1] == '{')
                {
                    tr = 0;
                    break;
                }
            }
            else if (s[i] == '{')
            {
                left_big += 1;
                if (i == s.size() - 1)
                {
                    tr = 0;
                    break;
                }
                else if (s[i + 1] == ')' || s[i + 1] == ']')
                {
                    tr = 0;
                    break;
                }
            }
            else if (s[i] == '}')
            {
                right_big += 1;
                if (i == 0)
                {
                    tr = 0;
                    break;
                }
                else if (s[i - 1] == '(' || s[i - 1] == '[')
                {
                    tr = 0;
                    break;
                }
            }
        }
        if (left_small != right_small || left_middle != right_middle || left_big != right_big)
        {
            tr = 0;
        }
        return tr;
    }
};
