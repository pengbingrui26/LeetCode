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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *New = head;
        ListNode *Old = head->next;
        if (Old == nullptr)
        {
            return New;
        }
        ListNode *tmp = Old->next;
        if (tmp == nullptr)
        {
            Old->next = New;
            New->next = nullptr;
            return Old;
        }
        else
        {
            while (tmp)
            {
                Old->next = New;
                New = Old;
                Old = tmp;
                tmp = tmp->next;
            }
            Old->next = New;
            head->next = nullptr;
            return Old;
        }
    }
};

// =======================================================

int main()
{
}