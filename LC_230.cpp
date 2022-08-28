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
    std::vector<int> inorder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        else
        {
            std::vector<int> left_arr = inorder(root->left);
            left_arr.push_back(root->val);
            std::vector<int> right_arr = inorder(root->right);
            left_arr.insert(left_arr.end(), right_arr.begin(), right_arr.end());
            return left_arr;
        }
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        std::vector<int> output = inorder(root);
        for (int i = output.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (output[j] < output[j + 1])
                {
                    int tmp = output[j];
                    output[j] = output[j + 1];
                    output[j + 1] = tmp;
                }
            }
        }
        return output[output.size() - k];
    }
};

int main()
{
}