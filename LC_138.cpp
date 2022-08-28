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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        std::unordered_map<int, Node *> hashlist;
        std::unordered_map<Node *, int> hashlist_reverse;
        std::unordered_map<int, Node *> random_list;

        int n = 0;
        Node *thisnode = head;
        while (thisnode)
        {
            hashlist[n] = thisnode;
            hashlist_reverse[thisnode] = n;
            random_list[n] = thisnode->random;
            n++;
            thisnode = thisnode->next;
        }

        Node *head_new = new Node(0);

        int k = 0;
        Node *tmp_node = head_new;
        std::unordered_map<int, Node *> hashlist_new;
        while (k < n)
        {
            tmp_node->val = hashlist[k]->val;
            hashlist_new[k] = tmp_node;
            if (k == n - 1)
                tmp_node->next = nullptr;
            else
            {
                Node *next_node = new Node(0);
                tmp_node->next = next_node;
            }
            tmp_node = tmp_node->next;
            k++;
        }

        int r = 0;
        Node *node_tmp = head_new;
        while (r < n)
        {
            auto random_tmp = random_list[r];
            if (random_tmp != nullptr)
                node_tmp->random = hashlist_new[hashlist_reverse[random_tmp]];
            else
                node_tmp->random = nullptr;
            node_tmp = node_tmp->next;
            r++;
        }
        return head_new;
    }
};

int main()
{
}
