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

class Solution1
{
public:
    // private:
    std::vector<int> levelorderTraversal(TreeNode *root)
    {
        std::vector<int> output;
        if (root)
        {
            std::queue<TreeNode *> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *tmp = q.front();
                output.push_back(tmp->val);
                q.pop();
                if (tmp->left)
                {
                    q.push(tmp->left);
                }
                if (tmp->right)
                {
                    q.push(tmp->right);
                }
            }
        }
        return output;
    }
    // public:
    bool isSymmetric(TreeNode *root)
    {
        auto output = levelorderTraversal(root);
        bool symmetric = 1;
        int total_num = 0;
        int i = 0;
        while (std::pow(2, i) - 1 < output.size())
        {
            std::vector<int> this_arr;
            for (int j = std::pow(2, i) - 1; j < std::pow(2, i + 1) - 1; j++)
            {
                if (j >= output.size())
                {
                    break;
                }
                this_arr.push_back(output[j]);
            }
            // print(this_arr);
            if (this_arr.size() != std::pow(2, i))
            {
                return 0;
            }
            int front = 0;
            int back = this_arr.size() - 1;
            bool symmetric_arr = 1;
            while (front <= back)
            {
                if (this_arr[front] != this_arr[back])
                {
                    symmetric_arr = 0;
                    break;
                }
                front++;
                back--;
            }
            if (!symmetric_arr)
            {
                symmetric = 0;
                break;
            }
            // print(this_arr);
            i++;
        }
        return symmetric;
    }
};

class Solution2
{
private:
    bool check(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
        {
            if (p || q)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return (p->val == q->val && check(p->left, q->right) && check(p->right, q->left));
        }
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *p = root;
        TreeNode *q = root;
        bool symmetric = check(p, q);
        return symmetric;
    }
};

// ==============================================================

void test01()
{
    // Creat a TreeNode
    TreeNode *root = new TreeNode;
    root->val = 1;

    TreeNode *t11 = new TreeNode;
    t11->val = 2;
    root->left = t11;

    TreeNode *t12 = new TreeNode;
    t12->val = 2;
    root->right = t12;

    TreeNode *t21 = new TreeNode;
    t21->val = 3;
    t11->left = t21;

    TreeNode *t22 = new TreeNode;
    t22->val = 4;
    t11->right = t22;

    TreeNode *t23 = new TreeNode;
    t23->val = 4;
    t12->left = t23;

    TreeNode *t24 = new TreeNode;
    t24->val = 3;
    t12->right = t24;

    Solution1 solution;
    auto vv = solution.levelorderTraversal(root);
    print(vv);

    auto tr = solution.isSymmetric(root);
    std::cout << tr << std::endl;
}

void test02()
{
    // Creat a TreeNode
    TreeNode *root = new TreeNode;
    root->val = 1;

    TreeNode *t11 = new TreeNode;
    t11->val = 0;
    root->left = t11;

    Solution1 solution;
    auto vv = solution.levelorderTraversal(root);
    print(vv);

    auto tr = solution.isSymmetric(root);
    std::cout << tr << std::endl;
}

void test03()
{
    // Creat a TreeNode
    TreeNode *root = new TreeNode;
    root->val = 1;

    TreeNode *t11 = new TreeNode;
    t11->val = 2;
    root->left = t11;

    TreeNode *t12 = new TreeNode;
    t12->val = 2;
    root->right = t12;

    // TreeNode *t21 = new TreeNode;
    // t21->val = 3;
    t11->left = nullptr;

    TreeNode *t22 = new TreeNode;
    t22->val = 3;
    t11->right = t22;

    TreeNode *t23 = new TreeNode;
    t23->val = 3;
    t12->left = t23;

    // TreeNode *t24 = new TreeNode;
    // t24->val = 3;
    t12->right = nullptr;

    Solution1 solution;
    auto vv = solution.levelorderTraversal(root);
    print(vv);

    auto tr = solution.isSymmetric(root);
    std::cout << tr << std::endl;
}

// ==============================================================

int main()
{
    // test01();
    // test02();
    test03();
}