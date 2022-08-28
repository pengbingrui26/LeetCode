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
public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        else if (preorder.size() == 1)
        {
            TreeNode *node = new TreeNode;
            node->val = preorder[0];
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }
        else
        {
            int root_val = preorder[0];
            int idx = 0;
            while (idx < inorder.size())
            {
                if (inorder[idx] == root_val)
                    break;
                idx++;
            }
            TreeNode *root = new TreeNode;
            root->val = root_val;

            std::vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + idx + 1);
            std::vector<int> left_inorder(inorder.begin(), inorder.begin() + idx);

            std::vector<int> right_preorder(preorder.begin() + idx + 1, preorder.end());
            std::vector<int> right_inorder(inorder.begin() + idx + 1, inorder.end());

            TreeNode *left = buildTree(left_preorder, left_inorder);
            TreeNode *right = buildTree(right_preorder, right_inorder);

            root->left = left;
            root->right = right;

            return root;
        }
    }
};

int main()
{
}
