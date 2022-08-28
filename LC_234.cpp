#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

void print(std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution1
{
public:
    bool isPalindrome(ListNode *head)
    {
        std::vector<int> datas;
        ListNode *thisnode = head;
        while (thisnode)
        {
            datas.push_back(thisnode->val);
            thisnode = thisnode->next;
        }
        if (datas.size() <= 1)
        {
            return 1;
        }
        else
        {
            bool tr = 1;
            int i = 0;
            int j = datas.size() - 1;
            while (i <= j)
            {
                if (datas[i] != datas[j])
                {
                    return 0;
                }
                i++;
                j--;
            }
            return tr;
        }
    }
};

// ===========================================================================

int main()
{
}