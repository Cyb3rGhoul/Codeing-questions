#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size() - 1;
        while (i < n)
        {
            int j = i + 1;
            if (nums[i] == nums[j])
            {
                return nums[i];
            }
            else
            {
                i++;
            }
        }
        return 0;
    }
};