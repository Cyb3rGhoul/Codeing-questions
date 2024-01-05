#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str)
{
    int i = 0;
    int len = str.length() - 1;
    while (i < len)
    {
        if (str[i] != str[len])
        {
            return false;
        }
        else
        {
            i++;
            len--;
        }
    }
    return true;
}
