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
private:
    int minval(TreeNode *root)
    {
        TreeNode *thisnode = root;
        while (thisnode->left)
        {
            thisnode = thisnode->left;
        }
        return thisnode->val;
    }
    int maxval(TreeNode *root)
    {
        TreeNode *thisnode = root;
        while (thisnode->right)
        {
            thisnode = thisnode->right;
        }
        return thisnode->val;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return 1;
        else
        {
            if ((root->left == nullptr) && (root->right == nullptr))
            {
                return 1;
            }
            else if (root->right == nullptr)
            {
                int max_val = maxval(root->left);
                if (root->val <= max_val)
                    return 0;
                else
                    return isValidBST(root->left);
            }
            else if (root->left == nullptr)
            {
                int min_val = minval(root->right);
                if (root->val >= min_val)
                    return 0;
                else
                    return isValidBST(root->right);
            }
            else
            {
                int max_val = maxval(root->left);
                int min_val = minval(root->right);
                // std::cout << min_val << ", " << max_val << std::endl;
                if (root->val <= max_val || root->val >= min_val)
                    return 0;
                else
                    return (isValidBST(root->left) && isValidBST(root->right));
            }
        }
    }
};

int main()
{
}