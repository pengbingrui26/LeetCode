#include <iostream>
#include <vector>

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
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
        {
            std::vector<int> output;
            return output;
        }
        else
        {
            std::vector<int> output = inorderTraversal(root->left);
            output.push_back(root->val);
            std::vector<int> output_right = inorderTraversal(root->right);
            output.insert(output.end(), output_right.begin(), output_right.end());
            return output;
        }
    }
};

// =====================================================================

int main()
{
}
