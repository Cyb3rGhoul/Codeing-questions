#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        if (s.length() == 1)
        {
            return 0;
        }
        int count = 0;
        int i = 0;
        while (i < s.length())
        {
            int j = 0;
            while (j < s.length())
            {
                if (i == j)
                {
                    j++;
                }
                else if (s[i] == s[j])
                {
                    count++;
                    break;
                }
                else
                {
                    j++;
                }
            }
            if (count == 1)
            {
                count = 0;
                i++;
            }
            else
            {
                return i;
            }
        }
        return -1;
    }
};