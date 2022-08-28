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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
};

class Solution
{
private:
    bool helper(int n)
    {
        bool tr = 0;
        for (int i = 1; i <= 12; i++)
        {
            if (std::pow(2, i) - 1 == n)
            {
                tr = 1;
                break;
            }
        }
        return tr;
    }

public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        std::queue<Node *> qq;
        qq.push(root);
        std::unordered_map<int, Node *> hashlist;
        int idx = 0;
        while (!qq.empty())
        {
            Node *tmp = qq.front();
            if (tmp->left)
                qq.push(tmp->left);
            if (tmp->right)
                qq.push(tmp->right);
            idx++;
            hashlist[idx] = tmp;
            qq.pop();
        }
        for (auto it : hashlist)
        {
            int k = it.first;
            Node *thisnode = it.second;
            if (helper(k))
            {
                thisnode->next = nullptr;
            }
            else
            {
                thisnode->next = hashlist[k + 1];
            }
        }
        return root;
    }
};

// ===================================================

void test01()
{
    Node *root = new Node;
    root->val = 1;
    Node *ll = new Node;
    ll->val = 2;
    Node *rr = new Node;
    rr->val = 3;

    root->left = ll;
    root->right = rr;

    // std::cout << root->left->val << std::endl;

    Solution solution;
    auto it = solution.connect(root);
    auto pp = it->left->next;
    std::cout << pp->val << std::endl;
}

// ===================================================

int main()
{
    test01();
}
