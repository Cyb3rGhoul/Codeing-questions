class Solution
{

private:
    int height(struct Node *node)
    {
        // code here
        if (node == NULL)
        {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;

        return ans;
    }

public:
    pair<bool, int> isBalancedFast(Node *root)
    {
        // Base case
        if (root == NULL)
        {
            pair<bool, int> t = make_pair(true, 0);
            return t;
        }
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(right.second - left.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        if (leftAns && rightAns && diff)
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};