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
    void deleteNode(ListNode *node)
    {
        ListNode *thisnode = node;
        while (thisnode->next != nullptr)
        {
            thisnode->val = thisnode->next->val;
            if (thisnode->next->next == nullptr)
            {
                thisnode->next = nullptr;
                break;
            }
            thisnode = thisnode->next;
        }
        thisnode = nullptr;
    }
};

int main()
{
}