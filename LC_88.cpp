#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

class Solution1
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        std::vector<int> sorted;
        int i = 0;
        int j = 0;
        while (i < m || j < n)
        {
            if (i == m)
            {
                sorted.push_back(nums2[j++]);
            }
            else if (j == n)
            {
                sorted.push_back(nums1[i++]);
            }
            else
            {
                if (nums1[i] > nums2[j])
                {
                    sorted.push_back(nums2[j++]);
                }
                else if (nums1[i] < nums2[j])
                {
                    sorted.push_back(nums1[i++]);
                }
                else
                {
                    sorted.push_back(nums1[i++]);
                    sorted.push_back(nums2[j++]);
                }
            }
            // std::cout << "i, j: " << i << ", " << j << std::endl;
            // print(sorted);
        }
        for (int k = 0; k < m; k++)
        {
            nums1[k] = sorted[k];
        }
        for (int r = 0; r < n; r++)
        {
            nums1.push_back(sorted[m + r]);
        }
    }
};

class Solution2
{
public:
    std::vector<int> merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        std::vector<int> sorted;
        while (!nums1.empty() && !nums2.empty())
        {
            if (nums1[0] > nums2[0])
            {
                sorted.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
            else if (nums1[0] < nums2[0])
            {
                sorted.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else
            {
                sorted.push_back(nums1[0]);
                nums1.erase(nums1.begin());
                sorted.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        if (!nums1.empty())
        {
            while (!nums1.empty())
            {
                sorted.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
        }
        if (!nums2.empty())
        {
            while (!nums2.empty())
            {
                sorted.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        return sorted;
    }
};

// ===================================================================================

void test01()
{
    Solution1 solution;
    std::vector<int> nums1 = {2, 3};
    std::vector<int> nums2 = {1, 4};
    int m = 2;
    int n = 2;
    solution.merge(nums1, m, nums2, n);
    print(nums1);
}

void test02()
{
    Solution2 solution;
    std::vector<int> nums1 = {2, 3};
    std::vector<int> nums2 = {1, 4};
    int m = 2;
    int n = 2;
    auto sorted = solution.merge(nums1, m, nums2, n);
    print(sorted);
}

// ==================================================

int main()
{
    // test01();
    test02();
}
