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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        std::vector<std::vector<int>> output;
        std::queue<TreeNode *> qq;
        qq.push(root);
        int nlevel = 0;
        while (!qq.empty())
        {
            int len = qq.size();
            std::vector<int> v;
            for (int i = 0; i < len; i++)
            {
                auto node = qq.front();
                v.push_back(node->val);
                qq.pop();
                if (node->left)
                    qq.push(node->left);
                if (node->right)
                    qq.push(node->right);
            }
            if (nlevel % 2 == 1)
                std::reverse(v.begin(), v.end());
            output.push_back(v);
            nlevel++;
        }
        return output;
    }
};

int main()
{
}
