#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        int end = s.length();
        for (int i = end - 1; i >= 0; i--)
        {
            if (s[i] == 'I')
            {
                ans = ans + 1;
            }
            else if (s[i] == 'V' && i > 0 && s[i - 1] == 'I')
            {
                ans = ans + 4;
                i--;
            }
            else if (s[i] == 'V')
            {
                ans = ans + 5;
            }
            else if (s[i] == 'X' && i > 0 && s[i - 1] == 'I')
            {
                ans = ans + 9;
                i--;
            }
            else if (s[i] == 'X')
            {
                ans = ans + 10;
            }
            else if (s[i] == 'L' && i > 0 && s[i - 1] == 'X')
            {
                ans = ans + 40;
                i--;
            }
            else if (s[i] == 'L')
            {
                ans = ans + 50;
            }
            else if (s[i] == 'C' && i > 0 && s[i - 1] == 'X')
            {
                ans = ans + 90;
                i--;
            }
            else if (s[i] == 'C')
            {
                ans = ans + 100;
            }
            else if (s[i] == 'D' && i > 0 && s[i - 1] == 'C')
            {
                ans = ans + 400;
                i--;
            }
            else if (s[i] == 'D')
            {
                ans = ans + 500;
            }
            else if (s[i] == 'M' && i > 0 && s[i - 1] == 'C')
            {
                ans = ans + 900;
                i--;
            }
            else if (s[i] == 'M')
            {
                ans = ans + 1000;
            }
        }
        return ans;
    }
};
