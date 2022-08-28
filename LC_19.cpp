#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>

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

class Solution1
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        std::unordered_map<int, ListNode *> HashList;
        auto thisnode = head;
        if (head->next == nullptr)
        {
            return nullptr;
        }
        int i = 0;
        while (thisnode)
        {
            HashList[i] = thisnode;
            thisnode = thisnode->next;
            i++;
        }
        i--;
        int idx = (i + 1) - n;
        if (idx == 0)
        {
            // return nullptr;
            return HashList[1];
        }
        auto node = HashList[idx - 1];
        auto node_del = HashList[idx];
        node->next = node_del->next;
        return head;
    }
};

class Solution2
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        std::unordered_map<int, ListNode *> HashList;
        ListNode *node_dummy = new ListNode;
        node_dummy->next = head;
        auto thisnode = node_dummy;
        int i = 0;
        while (thisnode)
        {
            HashList[i] = thisnode;
            thisnode = thisnode->next;
            i++;
        }
        i--;
        int idx = (i + 1) - n;
        auto node = HashList[idx - 1];
        auto node_del = HashList[idx];
        node->next = node_del->next;
        ListNode *ans = node->next;
        delete node_dummy;
        return ans;
    }
};

// stack

class Solution3
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        std::stack<ListNode *> ss;
        ListNode *node_dummy = new ListNode;
        node_dummy->next = head;
        auto thisnode = node_dummy;
        while (thisnode)
        {
            ss.push(thisnode);
            thisnode = thisnode->next;
        }
        int i = 1;
        while (i <= n)
        {
            ss.pop();
            i++;
        }
        auto front_node = ss.top();
        front_node->next = front_node->next->next;
        auto ans = node_dummy->next;
        delete node_dummy;
        return ans;
    }
};

// ==================================================================================

int main()
{
}