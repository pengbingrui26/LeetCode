#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *node = new ListNode;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *thisnode = node;

        bool add_pos = 0;
        while (p1 && p2)
        {
            int val = p1->val + p2->val;
            if (add_pos)
            {
                val += 1;
            }
            if (val >= 10)
            {
                add_pos = 1;
                val -= 10;
            }
            else
            {
                add_pos = 0;
            }
            thisnode->val = val;
            p1 = p1->next;
            p2 = p2->next;
            if (p1 || p2)
            {
                ListNode *nextnode = new ListNode;
                thisnode->next = nextnode;
                thisnode = nextnode;
            }
        }
        if (p1 || p2)
        {
            ListNode *pp = (p1) ? p1 : p2;
            while (pp)
            {
                int val = pp->val;
                if (add_pos)
                {
                    val += 1;
                }
                if (val >= 10)
                {
                    add_pos = 1;
                    val -= 10;
                }
                else
                {
                    add_pos = 0;
                }
                thisnode->val = val;
                pp = pp->next;
                if (pp)
                {
                    ListNode *nextnode = new ListNode;
                    thisnode->next = nextnode;
                    thisnode = nextnode;
                }
            }
        }
        if (add_pos)
        {
            ListNode *nextnode = new ListNode;
            thisnode->next = nextnode;
            nextnode->val = 1;
        }
        return node;
    }
};

int main()
{
}