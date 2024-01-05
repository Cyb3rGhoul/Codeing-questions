#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxi = 0;
        int count = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == 1)
            {
                count++;
                i++;
            }
            else
            {
                maxi = max(maxi, count);
                count = 0;
                i++;
            }
        }
        return max(maxi, count);
    }
};
