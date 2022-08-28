#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

void print(std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            int depth = 1 + std::max(maxDepth(root->left), maxDepth(root->right));
            return depth;
        }
    }

public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        int depth = maxDepth(root);

        std::vector<std::vector<TreeNode *>> vv;
        std::vector<std::vector<int>> vv_val;
        if (depth == 0)
        {
            return vv_val;
        }

        std::vector<TreeNode *> v_init = {root};
        vv.push_back(v_init);
        std::vector<int> v_val_init = {root->val};
        vv_val.push_back(v_val_init);

        if (depth == 1)
        {
            return vv_val;
        }

        for (int i = 2; i <= depth; i++)
        {
            auto v_tmp = vv.back();
            std::vector<TreeNode *> v_next;
            auto v_val_tmp = vv_val.back();
            std::vector<int> v_val_next;
            for (auto node : v_tmp)
            {
                if (node->left)
                {
                    v_next.push_back(node->left);
                    v_val_next.push_back(node->left->val);
                }
                if (node->right)
                {
                    v_next.push_back(node->right);
                    v_val_next.push_back(node->right->val);
                }
            }
            vv.push_back(v_next);
            vv_val.push_back(v_val_next);
        }

        return vv_val;
    }
};