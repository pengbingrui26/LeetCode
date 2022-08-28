#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <set>

void print(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

class Solution1
{
public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_map<int, int> HashList1;
        std::unordered_map<int, int> HashList2;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (HashList1.find(nums1[i]) == HashList1.end())
            {
                HashList1[nums1[i]] = 1;
            }
            else
            {
                HashList1[nums1[i]]++;
            }
        }
        for (int j = 0; j < nums2.size(); j++)
        {
            if (HashList2.find(nums2[j]) == HashList2.end())
            {
                HashList2[nums2[j]] = 1;
            }
            else
            {
                HashList2[nums2[j]]++;
            }
        }
        std::vector<int> output;
        for (auto it = HashList1.begin(); it != HashList1.end(); it++)
        {
            if (HashList2.find(it->first) != HashList2.end())
            {
                int times = (it->second <= HashList2[it->first]) ? it->second : HashList2[it->first];
                output.insert(output.end(), times, it->first);
            }
        }
        return output;
    }
};

class Solution2
{
public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        std::vector<int> output;
        while (i < nums1.size() && j < nums2.size())
        {
            // std::cout << "j:" << j << std::endl;
            if (i == nums1.size() - 1 && j == nums2.size() - 1)
            {
                break;
            }
            while (nums1[i] > nums2[j])
            {
                // if (i == nums1.size() - 1 && j == nums2.size() - 1)
                //{
                //     break;
                // }
                j++;
            }
            if (nums1[i] == nums2[j])
            {
                int di = i;
                while (di < nums1.size() - 1)
                {
                    if (nums1[di + 1] > nums1[di])
                    {
                        break;
                    }
                    di++;
                }
                int dj = j;
                while (dj < nums2.size() - 1)
                {
                    if (nums2[dj + 1] > nums2[dj])
                    {
                        break;
                    }
                    dj++;
                }
                int ntimes = std::min((di - i + 1), (dj - j + 1));
                output.insert(output.end(), ntimes, nums1[i]);
                print(output);
                i = di + 1;
                j = dj + 1;
            }
            else
            {
                i++;
            }
            std::cout << "i, j:" << i << ", " << j << std::endl;
        }
        return output;
    }
};

// ======================================================================

void test02()
{
    Solution2 solution;
    std::vector<int> nums1 = {4, 3, 9, 3, 1, 9, 7, 6, 9, 7};
    std::vector<int> nums2 = {5, 0, 8};
    auto v = solution.intersect(nums1, nums2);
    print(v);
}

// ======================================================================

int main()
{
    test02();
}
