#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> output;
        std::vector<int> arr = {1, 1};
        if (numRows == 1)
        {
            output.push_back({1});
        }
        else if (numRows == 2)
        {
            output.push_back({1});
            output.push_back({1, 1});
        }
        else
        {
            output.push_back({1});
            output.push_back({1, 1});
            int i = 3;
            while (i <= numRows)
            {
                std::vector<int> arr_new;
                arr_new.push_back(1);
                for (int k = 0; k < arr.size() - 1; k++)
                {
                    arr_new.push_back(arr[k] + arr[k + 1]);
                }
                arr_new.push_back(1);
                output.push_back(arr_new);
                arr = arr_new;
                i++;
            }
        }
        return output;
    }
};

// ===============================================================

int main()
{
}
