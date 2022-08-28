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
    bool hasCycle(ListNode *head)
    {
        std::unordered_map<ListNode *, int> HashList;
        int pos;
        bool tr = 0;
        int i = 0;
        ListNode *thisnode = head;
        while (thisnode)
        {
            if (HashList.find(thisnode->next) != HashList.end())
            {
                pos = HashList[thisnode->next];
                tr = 1;
                break;
            }
            HashList[thisnode] = i;
            i++;
            thisnode = thisnode->next;
        }
        return tr;
    }
};

// ============================================================================================

// ============================================================================================

int main()
{
}
