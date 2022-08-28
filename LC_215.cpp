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

class Solution1
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        if (nums.size() == 1)
            return nums[0];
        for (int i = nums.size() - 1; i >= nums.size() - k; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                }
            }
        }
        return nums[nums.size() - k];
    }
};

class Solution2
{
public:
    void maxHeapify(std::vector<int> &a, int i, int heapSize)
    {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest])
        {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            std::swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(std::vector<int> &a, int heapSize)
    {
        for (int i = heapSize / 2; i >= 0; --i)
        {
            std::cout << "i: " << i << std::endl;
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargest(std::vector<int> &nums, int k)
    {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i)
        {
            std::swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

// ===============================================

void test02()
{
    Solution2 solution;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    solution.buildMaxHeap(nums, nums.size());
    print(nums);
    // auto it = solution.findKthLargest(nums, 2);
    // std::cout << it << std::endl;
}

// ===============================================

int main()
{
    test02();
}