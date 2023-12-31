#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to check whether the list is palindrome.

    bool checkPallindrome(vector<int> arr)
    {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            if (arr[s] != arr[e])
            {
                return 0;
            }
            else
            {
                s++;
                e--;
            }
        }
        return true;
    }
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        return checkPallindrome(arr);
    }
};