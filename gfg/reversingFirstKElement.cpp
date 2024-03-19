//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k)
    {
        // Algorithm
        // step 1: pop first K element of the queue and put them into Stack

        int n = q.size();
        stack<int> s;
        for (int i = 0; i < k; i++)
        {
            int val = q.front();
            q.pop();
            s.push(val);
        }

        // step 2: fetch from the stack and push into queue
        for (int i = 0; i < k; i++)
        {
            int val = s.top();
            s.pop();
            q.push(val);
        }

        for (int i = 0; i < (n - k); i++)
        {
            int val = q.front();
            q.pop();
            q.push(val);
        }

        return q;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends