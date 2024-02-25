#include <bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // ch ya to ')' ya to lower case

            if (ch == ')')
            {
                bool isReduntent = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isReduntent = false;
                    }
                    st.pop();
                }
                if (isReduntent)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
