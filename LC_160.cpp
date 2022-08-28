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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // ListNode* nodeA = headA;
        // ListNode* nodeB = headB;
        for (ListNode *nodeA = headA; nodeA != nullptr; nodeA = nodeA->next)
        {
            for (ListNode *nodeB = headB; nodeB != nullptr; nodeB = nodeB->next)
                if (nodeA == nodeB)
                {
                    ListNode *tmpA = nodeA;
                    ListNode *tmpB = nodeB;
                    while (tmpA && tmpB)
                    {
                        if (tmpA != tmpB)
                            break;
                        tmpA = tmpA->next;
                        tmpB = tmpB->next;
                    }
                    if (tmpA == nullptr && tmpB == nullptr)
                        return nodeA;
                }
        }
        return nullptr;
    }
};

int main()
{
}
