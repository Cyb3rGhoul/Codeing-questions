class Solution
{
public:
    int missingNumber(vector<int> &array, int n)
    {
        sort(array.begin(), array.end());

        for (int i = 0; i < n; i++)
        {
            if ((i + 1) == array[i])
            {
                continue;
            }
            else
            {
                return i + 1;
            }
        }
    }
};