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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        std::unordered_map<int, ListNode *> hashlist;
        int i = 0;
        ListNode *node = head;
        while (node)
        {
            hashlist[i] = node;
            node = node->next;
            i++;
        }
        int N = i;
        for (int i = N - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (hashlist[j]->val > hashlist[j + 1]->val)
                {
                    auto tmp = hashlist[j]->val;
                    hashlist[j]->val = hashlist[j + 1]->val;
                    hashlist[j + 1]->val = tmp;
                }
            }
        }
        return head;
    }
};

int main()
{
}