class Solution
{
public:
    void traverseLeft(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        ans.push_back(root->data);
        if (root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    void traverseLeafe(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        traverseLeafe(root->left, ans);
        traverseLeafe(root->right, ans);
    }

    void traverseRight(Node *root, vector<int> &ans)
    {
        // base case
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        if (root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        // wapas aagaye
        ans.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        ans.push_back(root->data);

        // left part print
        traverseLeft(root->left, ans);

        // traverse leafe node
        // left sub tree
        traverseLeafe(root->left, ans);

        // Right sub tree
        traverseLeafe(root->right, ans);

        traverseRight(root->right, ans);

        return ans;
    }
};