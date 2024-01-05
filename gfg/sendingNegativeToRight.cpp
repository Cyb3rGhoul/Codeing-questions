#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void segregateElements(int arr[], int n)
    {
        // first we will push our positive integers
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                ans.push_back(arr[i]);
            }
        }
        // now we will push negative integers
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                ans.push_back(arr[i]);
            }
        }
        // now we will update our array
        for (int i = 0; i < n; i++)
        {
            arr[i] = ans[i];
        }
    }
};