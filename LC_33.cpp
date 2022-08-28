#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>

void print(std::vector<int> &v)
{
    for (auto it : v)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

class Solution1
{
private:
    int Binarysearch(std::vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return -1;
        }
        else if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
            {
                std::cout << "nums: " << std::endl;
                print(nums);
                return -1;
            }
        }
        else
        {
            int middle = nums.size() / 2;
            if (nums[0] > target || nums[nums.size() - 1] < target)
            {
                return -1;
            }
            else if (nums[middle] == target)
            {
                return middle;
            }
            else if (nums[middle] > target)
            {
                std::vector<int> front;
                for (int i = 0; i < middle; i++)
                {
                    front.push_back(nums[i]);
                }
                return Binarysearch(front, target);
            }
            else
            {
                std::vector<int> hind;
                for (int i = middle + 1; i < nums.size(); i++)
                {
                    hind.push_back(nums[i]);
                }
                auto it = Binarysearch(hind, target);
                if (it != -1)
                {
                    return it + middle + 1;
                }
                else
                {
                    return -1;
                }
            }
        }
    }

public:
    int search(std::vector<int> &nums, int target)
    {
        if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        int idx = 0;
        while (idx < nums.size() - 1)
        {
            if (nums[idx + 1] < nums[idx])
            {
                break;
            }
            idx++;
        }
        idx++;
        std::cout << "idx: " << idx << std::endl;
        std::vector<int> front;
        std::vector<int> hind;
        for (int i = 0; i < idx; i++)
        {
            front.push_back(nums[i]);
        }
        if (idx < nums.size())
        {
            for (int j = idx; j < nums.size(); j++)
            {
                hind.push_back(nums[j]);
            }
        }
        auto x = Binarysearch(front, target);
        auto y = Binarysearch(hind, target);
        std::cout << "x:" << x << std::endl;
        std::cout << "y:" << y << std::endl;
        if (x != -1)
        {
            return x;
        }
        else if (y != -1)
        {
            return y + front.size();
        }
        else
        {
            return -1;
        }
    }
};

class Solution2
{
private:
    int Binarysearch(std::vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
        {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) / 2;
        if (nums[left] > target || nums[right] < target)
            return -1;
        while (left <= right)
        {
            if (nums[middle] > target)
            {
                right = middle - 1;
                middle = (left + right) / 2;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
                middle = (left + right) / 2;
            }
            else
                return middle;
        }
        if (nums[middle] != target)
            return -1;
        else
            return middle;
    }

public:
    int search(std::vector<int> &nums, int target)
    {
        if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        int idx = 0;
        while (idx < nums.size() - 1)
        {
            if (nums[idx + 1] < nums[idx])
            {
                break;
            }
            idx++;
        }
        idx++;
        std::vector<int> front;
        std::vector<int> hind;
        for (int i = 0; i < idx; i++)
        {
            front.push_back(nums[i]);
        }
        if (idx < nums.size())
        {
            for (int j = idx; j < nums.size(); j++)
            {
                hind.push_back(nums[j]);
            }
        }
        auto x = Binarysearch(front, target);
        auto y = Binarysearch(hind, target);
        if (x != -1)
        {
            return x;
        }
        else if (y != -1)
        {
            return y + front.size();
        }
        else
        {
            return -1;
        }
    }
};

// ============================================================

void test01()
{
    Solution1 solution;
    std::vector<int> nums = {1, 3, 5};
    int target = 4;
    auto it = solution.search(nums, target);
    std::cout << it << std::endl;
}

void test02()
{
    Solution2 solution;
    std::vector<int> nums = {1, 3, 5};
    int target = 4;
    auto it = solution.search(nums, target);
    std::cout << it << std::endl;
}

// ============================================================

int main()
{
    // test01();
    test02();
}