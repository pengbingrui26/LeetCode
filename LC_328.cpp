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
    ListNode *oddEvenList(ListNode *head)
    {
        std::vector<ListNode *> oddnodes;
        std::vector<ListNode *> evennodes;
        ListNode *node = head;
        int i = 0;
        while (node != nullptr)
        {
            if (i % 2 == 0)
            {
                oddnodes.push_back(node);
            }
            else
            {
                evennodes.push_back(node);
            }
            i++;
            node = node->next;
        }
        // std::cout << 1 << std::endl;
        ListNode *new_head = new ListNode;
        ListNode *node_tmp = new_head;
        for (auto odd_node : oddnodes)
        {
            node_tmp->next = odd_node;
            node_tmp = node_tmp->next;
        }
        // std::cout << 1 << std::endl;
        for (auto evennode : evennodes)
        {
            node_tmp->next = evennode;
            node_tmp = node_tmp->next;
        }
        node_tmp->next = nullptr;
        // std::cout << 1 << std::endl;
        // std::cout << new_head->next->val << std::endl;
        return new_head->next;
    }
};

class Solution2
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *odd_node = head;
        ListNode *even_node_first = head->next;
        ListNode *even_node = even_node_first;

        while (odd_node && even_node)
        {
            if (even_node->next == nullptr)
                break;
            odd_node->next = even_node->next;
            odd_node = odd_node->next;
            even_node->next = odd_node->next;
            even_node = even_node->next;
        }

        odd_node->next = even_node_first;
        return head;
    }
};

int main()
{
}
