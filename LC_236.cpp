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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
private:
    bool search(TreeNode *root, TreeNode *r)
    {
        if (root == nullptr)
            return 0;
        if (root == r)
            return 1;
        else
        {
            bool re_l = search(root->left, r);
            bool re_r = search(root->right, r);
            if (re_l || re_r)
                return 1;
            else
                return 0;
        }
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        std::vector<TreeNode *> all_nodes;
        std::queue<TreeNode *> qq;
        qq.push(root);
        while (!qq.empty())
        {
            auto node_tmp = qq.front();
            all_nodes.push_back(node_tmp);
            if (node_tmp->left)
                qq.push(node_tmp->left);
            if (node_tmp->right)
                qq.push(node_tmp->right);
            qq.pop();
        }
        for (int i = all_nodes.size() - 1; i >= 0; i--)
        {
            auto node = all_nodes[i];
            bool re_p = search(node, p);
            bool re_q = search(node, q);
            if (re_p && re_q)
            {
                return node;
            }
        }
        return root;
    }
};

int main()
{
}
