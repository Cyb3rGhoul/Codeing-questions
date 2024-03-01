/*
Algorithm:

1. Push all the celebrities into a stack.

while stack size != 1

A -> s.top() -> s.pop()
B -> s.top() -> s.pop()

2. Pop the top two celebrities from the stack, and check if they know each other, if the current celebrity knows the other celebrity, then the current celebrity is not a celebrity, and push the other celebrity into the stack.

if (A knows B) {
    A is not a celebrity
    push B
} else {
    B is not a celebrity
    push A
}

3. If the current celebrity does not know the other celebrity, then the other celebrity is not a celebrity, and push the current celebrity into the stack.

Jo bacha hai wo ho sakta hai ki potential celebrity ho.

4. Repeat steps 2 and 3 until there is only one celebrity left in the stack.

Verify:

5. Check if the remaining celebrity is a celebrity by iterating through the array and checking if the remaining celebrity knows no one and everyone knows the remaining celebrity.

6. If the remaining celebrity is a celebrity, return the remaining celebrity, else return -1.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool knows(vector<vector<int>> M, int a, int b, int n)
    {
        if (M[a][b] == 1)
        {
            return true;
        }
        return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }
        // Step 2: get 2 element and compare them
        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (knows(M, a, b, n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        int ans = s.top();
        // Step 3: Single in the stack is potential celebrity
        // so verify it

        int zeroCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
            {
                zeroCount++;
            }
        }
        if (zeroCount != n)
        {
            return -1;
        }

        // colum check karo
        int colCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
            {
                colCount++;
            }
        }
        if (colCount != (n - 1))
        {
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends