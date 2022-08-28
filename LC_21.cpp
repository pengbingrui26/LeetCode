#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
};

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

class Solution1
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *sorted = new ListNode;
        ListNode *thisnode = sorted;
        while (list1 != nullptr || list2 != nullptr)
        {
            if (list1 == nullptr)
            {
                ListNode *tmp = new ListNode;
                tmp->val = list2->val;
                tmp->next = nullptr;
                thisnode->next = tmp;
                thisnode = tmp;
                list2 = list2->next;
            }
            else if (list2 == nullptr)
            {
                ListNode *tmp = new ListNode;
                tmp->val = list1->val;
                tmp->next = nullptr;
                thisnode->next = tmp;
                thisnode = tmp;
                list1 = list1->next;
            }
            else
            {
                if (list1->val > list2->val)
                {
                    ListNode *tmp = new ListNode;
                    tmp->val = list2->val;
                    tmp->next = nullptr;
                    thisnode->next = tmp;
                    thisnode = tmp;
                    list2 = list2->next;
                }
                else if (list1->val < list2->val)
                {
                    ListNode *tmp = new ListNode;
                    tmp->val = list1->val;
                    tmp->next = nullptr;
                    thisnode->next = tmp;
                    thisnode = tmp;
                    list1 = list1->next;
                }
                else
                {
                    ListNode *tmp1 = new ListNode;
                    ListNode *tmp2 = new ListNode;
                    tmp1->val = list1->val;
                    tmp2->val = list2->val;
                    tmp1->next = tmp2;
                    tmp2->next = nullptr;
                    thisnode->next = tmp1;
                    thisnode = tmp2;
                    list1 = list1->next;
                    list2 = list2->next;
                }
            }
        }
        ListNode *hh = sorted;
        sorted = sorted->next;
        delete hh;
        return sorted;
    }
};

// recursion

class Solution2
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
        else
        {
            if (list1->val < list2->val)
            {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            else
            {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
        }
    }
};

// =================================================================

ListNode *create(std::vector<int> vv)
{
    // create a ListNode
    ListNode *head = new ListNode;
    head->val = vv[0];
    ListNode *tmp = head;
    for (int i = 1; i < vv.size(); i++)
    {
        ListNode *node = new ListNode;
        node->val = vv[i];
        node->next = nullptr;
        tmp->next = node;
        tmp = node;
    }
    return head;
}

void enumerate(ListNode *node)
{
    ListNode *head = node;
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void test_basic()
{
    std::vector<int> vv = {1, 2, 3};
    auto node = create(vv);
    enumerate(node);
}

// =================================================================

int main()
{
    // test_basic();
}