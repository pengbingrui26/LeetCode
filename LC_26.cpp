#include <iostream>
#include <vector>

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
    int removeDuplicates(std::vector<int> &nums)
    {
        int N = nums.size();
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < N)
        {
            // std::cout << "i = " << i << std::endl;
            if (i < N - 1)
            {
                while (nums[i + j + 1] == nums[i])
                {
                    j++;
                }
            }
            // std::cout << "j = " << j << std::endl;
            nums.push_back(nums[i]);
            k++;
            i += (j + 1);
            j = 0;
        }
        // print(nums);
        for (int l = 0; l < k; l++)
        {
            int tmp = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), tmp);
        }
        // print(nums);
        for (int m = 0; m < N; m++)
        {
            nums.pop_back();
        }
        return k;
    }
};

class Solution2
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int N = nums.size();
        if (N == 0)
        {
            return 0;
        }
        else
        {
            int i = 0;
            int j = 1;
            int Num = i;
            while (i < N)
            {
                while ((i + j) < N)
                {
                    if (nums[i + j] != nums[i])
                    {
                        break;
                    }
                    j++;
                }
                i += j;
                if (i < N)
                {
                    Num++;
                    nums[Num] = nums[i];
                }
                j = 1;
            }
            for (int l = 0; l < (N - (Num + 1)); l++)
            {
                nums.pop_back();
            }
            return (Num + 1);
        }
    }
};

// double pointers

class Solution3
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int N = nums.size();
        if (N == 0)
        {
            return 0;
        }
        else if (N == 1)
        {
            return 1;
        }
        else
        {
            int j = 0;
            for (int i = 1; i < N; i++)
            {
                if (nums[i] != nums[i - 1])
                {
                    j++;
                    nums[j] = nums[i];
                }
            }
            for (int l = 0; l < (N - j - 1); l++)
            {
                nums.pop_back();
            }
            return j + 1;
        }
    }
};

// test ======================================================

void test01()
{
    Solution1 solution;
    std::vector<int> vv = {1, 1};
    auto k = solution.removeDuplicates(vv);
    std::cout << k << std::endl;
    print(vv);
}

void test02()
{
    Solution2 solution;
    std::vector<int> vv = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    auto k = solution.removeDuplicates(vv);
    std::cout << k << std::endl;
    print(vv);
}

void test03()
{
    Solution3 solution;
    std::vector<int> vv = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    auto k = solution.removeDuplicates(vv);
    std::cout << k << std::endl;
    print(vv);
}

// ===========================================================

int main()
{
    // test01();
    // test02();
    test03();
}