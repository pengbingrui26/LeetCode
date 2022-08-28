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
public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            TreeNode *node = new TreeNode;
            node->val = nums[0];
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }
        if (nums.size() == 2)
        {
            TreeNode *node1 = new TreeNode;
            node1->val = nums[0];
            node1->left = nullptr;
            node1->right = nullptr;

            TreeNode *node2 = new TreeNode;
            node2->val = nums[1];
            node2->left = node1;
            node2->right = nullptr;

            return node2;
        }
        else if (nums.size() == 3)
        {
            TreeNode *nodeL = new TreeNode;
            nodeL->val = nums[0];
            nodeL->left = nullptr;
            nodeL->right = nullptr;

            TreeNode *nodeR = new TreeNode;
            nodeR->val = nums[2];
            nodeR->left = nullptr;
            nodeR->right = nullptr;

            TreeNode *nodeM = new TreeNode;
            nodeM->val = nums[1];
            nodeM->left = nodeL;
            nodeM->right = nodeR;

            return nodeM;
        }
        else
        {
            std::vector<int> left_arr;
            std::vector<int> right_arr;
            for (int i = 0; i < nums.size() / 2; i++)
            {
                left_arr.push_back(nums[i]);
            }
            for (int j = nums.size() / 2 + 1; j < nums.size(); j++)
            {
                right_arr.push_back(nums[j]);
            }
            int middle = nums[nums.size() / 2];

            TreeNode *nodeM = new TreeNode;
            nodeM->val = middle;
            nodeM->left = sortedArrayToBST(left_arr);
            nodeM->right = sortedArrayToBST(right_arr);

            return nodeM;
        }
    }
};

// ============================================================

void test01()
{
}

// ============================================================
int main()
{
}